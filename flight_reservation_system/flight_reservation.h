#include<iostream>
#include <functional>
using namespace std;
#define size 100

class airlines
{
public:
	airlines();
  // ~airlines();
	void menu();
  void seat_fill();
	void make_reservation();
	void cancel_reservation();
	void search_passenger();
	void change_reservation();
	void print_list();
	void print_report();

  //Sorting test menu & its functions are below
    void test_menu();                                //shows the options for sort testing
    void add(string fileName);                     //add data into linkedlist through a file
    void generateData(int gen);                    //generate dataset for algorithm testing
    void askSortTiming(int option);      //track sorting time
    void selectSortingMethod(int sortByNum, int methodNum);        //selects sorting method to time
    void testAllSorts();
    void clearLinkedList();                            //clear linkedlist to help time algorithms
    template <typename T>
    void quickSort1(function<bool(const T*, const T*)> comp);          //uses normal quicksort
    template <typename T>
    void quickSort1Helper(T** arr, int s, function<bool(const T*, const T*)> comp);
    template <typename T>
    void insertionSort(T** arr, int s, function<bool(const T*, const T*)> comp);             //used to make quick sort faster
    template <typename T>
    void quickSort2(function<bool(const T*, const T*)> comp);  //uses quicksort with insertionsort
    template <typename T>
    void quickSort2Helper(T** arr, int s, function<bool(const T*, const T*)> comp);
    template <typename T>
    void mergeSort(T** start, function<bool(const T*, const T*)> comp);
    template <typename T>
    void split(T* source, T** firstStart, T** secondStart);
    template <typename T>
    T* merge(T* first, T* second, function<bool(const T*, const T*)> comp);

  private:
    struct node
    {
      string fname, lname, ID, phone_num, menu;
      int reserve_num, seat_num;


      node *next;

    };

    node *start;
    node *temp, *temp2;
    int trackSize = 0;                  //added to keep track of linkedlist size
    int maxSize = 100;


};
// bluesky;


