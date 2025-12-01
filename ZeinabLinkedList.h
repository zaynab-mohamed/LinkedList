//class definition
//simple linkedList
class List{
    //data members
    class node{
    public:
        int key;
        char data;
        node* next;
    };
    node* head, cursor , prev; //pointers
    //function members
    public:
        List();//defualt constructor
        ~List();//destructor
        bool ListIsEmpty(); //return true if list is empty
        bool CurIsEmpty(); //return true if the cursor is empty
        void toFirst(); //set cursor to head value
        bool atFirst(); //return true if cursor = head , or head & cursor are NULL
        void Advance();//to move current position to next node
        void toEnd();//to move current position to the last node
        bool atEnd();//return true if cursor is the tail node or list is empty
        int ListSize();//return count of nodes
        void updateData(char);//update data porsion in the current node
        void updateKey(int);//update key porsion in the current node
        char RetrieveData();//retrieve value in data variable
        void RetrieveData(char &);
        void insertFirst(int , char );
        void insertAfter(int , char );
        void insertBefore(int , char );
        void insertEnd(int , char );
        void DeleteNode();
        void DeleteFirst();
        void DeleteEnd();
        void makeListEmpty();//delete the whole list
        bool search( const int & ); //search for a key in the list
        void orderInsert(const int ,const char );
        void traverse();
};
