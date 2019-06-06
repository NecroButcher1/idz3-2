#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
template<typename T>
class queue{
private:
    struct node{
        T data;
        node *next,*prev;
    };
    node *tail,*head;
    size_t size;
public:
    queue():tail(nullptr),head(nullptr),size(0){};
    queue(const queue<T> *in){this = in;}
    queue operator=(queue &in){return in;}
    bool empty(){return ((!tail)||(!head));}
    void pop(){
        if(!empty()){
           size--;
           node* p=head;
           head=p->next;
           if(head)head->prev=nullptr;
           else tail=nullptr;
        }
    }
    void pop(T &_data){
        if(!empty()){
            size--;
            node *p=head;
            _data=p->data;
            head=p->next;
            if(head)head->prev=nullptr;
            else tail=nullptr;
            delete p;
        }
    }
    void push(T _data){
        node *p=new node;
        size++;
        p->data=_data;
        p->prev=tail;
        p->next=nullptr;
        if(tail)tail->next=p;
        tail=p;
        if(!head)head=tail;
    }
    T operator*(){
        if(!empty())return head->data;
    }
    void doEmpty(){
        if(!empty()){
            while(head)head=head->next;
            tail=nullptr;
            size=0;
        }
    }
    ~queue(){doEmpty();}
};


#endif // QUEUE_H_INCLUDED
