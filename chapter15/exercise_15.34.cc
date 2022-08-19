Query q = Query("fiery") & Query("bird") | Query("wind")

constructor;
Query("fiery") -> q(new WordQuery("fiery"))
Query("bird") -> q(new wordQuery("bird"))
Query("wind") -> q(new wordQuery("wind"))

Query("fiery") & Query("bird")
= AndQuery(Query("fiery"), Query("bird")) : BinaryQuery(Query("fiery"), Query("bird"), "&"){}

AndQuery(Query("fiery"), Query("bird")) | Query("wind")
= OrQuery(AndQuery(Query("fiery"), Query("bird")), Query("wind")):
    BinaryQuery(AndQuery(Query("fiery"), Query("bird")), Query("wind"), "|"){}


cout << q;
  OrQuery(AndQuery(Query("fiery"), Query("bird")), Query("wind")).rep()
= BinaryQuery(AndQuery(Query("fiery"), Query("bird")), Query("wind"), "|").rep()
= "(" + AndQuery(Query("fiery"), Query("bird")).rep() + " " +  "|"  + " " + Query("wind").rep() + ")";

AndQuery(Query("fiery"), Query("bird")).rep()
= BinaryQuery(Query("fiery"), Query("bird"), "&")
= "(" + Query("fiery").rep() + " " +  "&" + " " + Query("bird").rep() + ")";


Query("fiery").rep() = WordQuery("fiery").rep -> "fiery"
Query("bird").rep()  = WordQuery("bird").rep -> "bird"
Query("wind").rep()  = WordQuery("wind").rep -> "wind"

eval;
OrQuery(AndQuery(Query("fiery"), Query("bird")), Query("wind")).eval()
