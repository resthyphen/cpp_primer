#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <initializer_list>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::istream;
using std::ostream;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;
using std::list;
using std::map;
using std::set;
using std::pair;
using std::multimap;
using std::istringstream;
using std::runtime_error;
using std::make_shared;
using std::out_of_range;
using std::initializer_list;
using std::shared_ptr;
using std::weak_ptr;

class Folder;
class Message {
  friend class Folder;
  friend void swap(Message &lhs, Message &rhs);
  friend void swap(Folder&, Folder&);

public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = ""): contents(str) { }
    // copy control to manage pointers to this Message
    Message(const Message&);            // copy constructor
    Message& operator=(const Message&); // copy assignment
    ~Message();                         // destructor
    // add/remove this Message from the specified Folder's set of messages
    void save(Folder&);
    void remove(Folder&);
    Message(Message &&m);
    Message& operator=(Message &&rhs);

private:
    std::string contents;         // actual message text
    std::set<Folder*> folders;  // Folders that have this Message
    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message&);
    // remove this Message from every Folder in folders
    void remove_from_Folders();
    void addFolder(Folder *f);
    void remFolder(Folder *f);
    void move_Folders(Message *m);
};

class Folder {
  friend class Message;
  friend void swap(Message &, Message &);
  friend void swap(Folder&, Folder&);

public:
  Folder() = default;
  Folder(const Folder &orig);
  Folder& operator=(const Folder &rhs);
  ~Folder();
  void save(Message &);
  void remove(Message &);

private:
  set<Message*> messages;
  void addMsg(Message *);
  void remMsg(Message *);

  void add_to_Messages(const Folder& f);
  void remove_from_Messages();
};

void Message::save(Folder &f)
{
  folders.insert(&f); // add the given Folder to our list of Folders
  f.addMsg(this); // add this Message to f's set of Messages
}

void Message::remove(Folder &f)
{
  folders.erase(&f); // take the given Folder out of our list of Folders
  f.remMsg(this); // remove this Message to f's set of Messages
}

// add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m)
{
  for (auto f : m.folders) // for each Folder that holds m
    f->addMsg(this); // add a pointer to this Message to that Folder
}

Message::Message(const Message &m): contents(m.contents), folders(m.folders)
{
  add_to_Folders(m); // add this Message to the Folders that point to m
}

// remove this Message from the corresponding Folders
void Message::remove_from_Folders(){
    for (auto f : folders) // for each pointer in folders
        f->remMsg(this);   // remove this Message from that Folder
}

Message::~Message()
{
  remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
  // handle self-assignment by removing pointers before inserting them
  remove_from_Folders(); // update existing Folders
  contents = rhs.contents; // copy message contents from rhs
  folders = rhs.folders; // copy Folder pointers from rhs
  add_to_Folders(rhs); // add this Message to those Folders
  return *this;
}

void Message::addFolder(Folder *f){
  folders.insert(f);
}

void Message::remFolder(Folder *f){
  folders.erase(f);
}

void swap(Message &lhs, Message &rhs)
{
  using std::swap; // not strictly needed in this case, but good habit
  // remove pointers to each Message from their (original) respective Folders
  for (auto f: lhs.folders)
    f->remMsg(&lhs);
  for (auto f: rhs.folders)
    f->remMsg(&rhs);
  // swap the contents and Folder pointer sets
  swap(lhs.folders, rhs.folders); // uses swap(set&, set&)
  swap(lhs.contents, rhs.contents); // swap(string&, string&)
  // add pointers to each Message to their (new) respective Folders
  for (auto f: lhs.folders)
  f->addMsg(&lhs);
  for (auto f: rhs.folders)
  f->addMsg(&rhs);
}

void Message::move_Folders(Message *m){
  folders = std::move(m->folders); // uses set move assignment
  for (auto f : folders) { // for each Folder
    f->remMsg(m); // remove the old Message from the Folder
    f->addMsg(this); // add this Message to that Folder
  }
  m->folders.clear();
}

Message::Message(Message &&m):contents(std::move(m.contents))
{
  move_Folders(&m); // moves folders and updates the Folder pointers
}

Message& Message::operator=(Message &&rhs)
{
  if (this != &rhs) { // direct check for self-assignment
    remove_from_Folders();
    contents = std::move(rhs.contents); // move assignment
    move_Folders(&rhs); // reset the Folders to point to this Message
  }
  return *this;
}


void Folder::save(Message &m){
  messages.insert(&m);
  m.folders.insert(this);
}

void Folder::remove(Message &m) {
  messages.erase(&m);
  m.folders.erase(this);
}

void Folder::addMsg(Message *mp) {
  messages.insert(mp);
}


void Folder::remMsg(Message *mp) {
  messages.erase(mp);
}

void Folder::add_to_Messages(const Folder& f){
  for(auto m : f.messages)
    m->folders.insert(this);
}

void Folder::remove_from_Messages(){
  for(auto m : messages)
    m->folders.erase(this);
}

Folder::Folder(const Folder &orig):messages(orig.messages){
  add_to_Messages(orig);
}

Folder& Folder::operator=(const Folder &rhs){
  remove_from_Messages();
  messages = rhs.messages;
  add_to_Messages(rhs);
  return *this;
}

void swap(Folder &lhs, Folder &rhs){
  using std::swap;
  for(auto m : lhs.messages)
    m->remFolder(&lhs);
  for(auto m : rhs.messages)
    m->remFolder(&rhs);
  swap(lhs.messages, rhs.messages);
  for(auto m : lhs.messages)
    m->addFolder(&lhs);
  for(auto m : rhs.messages)
    m->addFolder(&rhs);
}

Folder::~Folder(){
  remove_from_Messages();
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
