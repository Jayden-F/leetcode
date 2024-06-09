#include <iostream>

// Question 1
template<class T>
struct Node
{
    // Add construct to allow use of initialise list.
    Node(T data, Node* next) : data_(data), next_(next) { }

    T data_;
    struct Node* next_;
};

template<class T>
class Stack
{
  private:
    Node<T>* tail_;

  public:
    Stack() { tail_ = nullptr; }

    ~Stack()
    {
        Node<T>* curr = tail_;

        while(curr != nullptr)
        {
            Node<T>* next = curr->next_;
            delete curr;
            curr = next;
        }
    }

    void
    Push(T data)
    {
        // construct node on heap.
        tail_ = new Node<T>(data, tail_);
    }

    T
    Pop()
    {
        // return -1 sentinel value.
        if(tail_ == nullptr) { return -1; }

        T data = tail_->data_;
        Node<T>* next = tail_->next_;
        delete tail_;

        tail_ = next;
        return data;
    }
};

// Question 2
void // We can pass the buffer in as a out param.
copyStr(const char* someStr, char& buf)
{
    // char buf[100];
    // sprintf(&buf, "%s", someStr);
    // return buf;
}

// Question 3
void
putlong(unsigned long a)
{

    unsigned long division = a / 10;
    unsigned long remainder = a % 10;

    if(division == 0)
    {
        putchar('0' + remainder);
        return;
    }

    putlong(division);
    // use post recursion to reverse print order not requiring array
    putchar('0' + remainder);
}

// Question 4
class Singleton
{
    static Singleton&
    get()
    {
        // on first call this will be initialised in static memory.
        // as it is a reference it is also thread safe.
        static Singleton instance;
        return instance;
    }

  private:
    // explicitly make constructor, destructor and copy constructor private.
    Singleton(){};
    ~Singleton(){};
    Singleton(const Singleton& other){};
};

// Question 5

/* ============================= outside 50mins (time additional 50mins)VVVVV*/
inline void
reverse_string(char* begin, char* end)
{
    while(begin < end)
    {
        // I am storing part the string. But, I am unsure, how else to do it.
        // typical swap  stuff.
        const char temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}

void
reverseWordsInString(char* const myString)
{
    char* word_left = myString;
    char* word_right = myString;

    // loop until end of word.
    while(*word_right != '\0')
    {
        // found end of word.
        if(*word_right == ' ')
        {
            // flip the word not including the space.
            reverse_string(word_left, word_right - 1);

            // update left pointer to start at next word.
            word_left = word_right + 1;
        }
        word_right++;
    }
    // found the end of the string, we must flip the last word.
    reverse_string(word_left, word_right - 1);
    // then flip entire string.
    reverse_string(myString, word_right - 1);
}
/* ============================= outside 50mins ^^^^^*/

int
main()
{
    // int test = 255;
    // putlong(test);
    // std::cout << std::endl;
    // Question 6
    // allocate some variables on the stack.
    // int my_nums[5] = {1, 2, 3, 4, 5};
    // std::cout << &test << std::endl;
    // for(size_t i = 0; i < 5; i++)
    // {
    //     std::cout << &my_nums[i] << std::endl;
    // }
    // printing the address and check if increasing

    // test for question 5
    char my_string[] = "the sky is blue";
    std::cout << my_string << std::endl;
    reverseWordsInString(my_string);
    std::cout << my_string << std::endl;
}

// Question 7
//
/* ============================= outside 50mins (time additional 5mins)VVVVV*/

// MALLOC: malloc is used by the program to request raw bytes from the
// operating system.
//
// NEW OPERATOR: the operator used to allocate and initialise an object on the
// heap.
//
// OPERATOR NEW: The class member function that is called when the new
// operator is called on an object.

/* ============================= outside 50mins ^^^^^*/

// Question 8
// What are the differences between std::list, std::vector and std::map.
// std::list is a doubly linked list. Allowing for constant time insert,
// remove. Trade off linear search and sparse memory allocation.
//
// std::vector is a dynamic size array. Worst case O(N) for insert and remove,
// contigous memory allocation allows for random access. If sorted you can
// binary search.
//
// std::map is a hash map. Therefore you should have constant lookup, remove
// and search. However, due its implementation as a tree the look up times are
// O(log N)

// Question 9
/* ============================= outside 50mins (time additional 10mins)VVVVV*/
float
angle_between_hands(int hh, int mm)
{
    // angle of hour hand - angle of minute hand = (30hh + mm/2) - 6m
    double angle = abs((hh * 30) - (11 / 2.0) * mm);
    return std::min(360 - angle, angle);
}
/* ============================= outside 50mins ^^^^^*/
