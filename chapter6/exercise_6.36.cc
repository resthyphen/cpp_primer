string (&func(int i)) [10];

typedef string arr[10];

using arr = string[10];

arr& func(int i);


string str[10];

decltype(str) &func(int i);

auto func(int i) -> string(&) [10]{
  return str
}
