#include <iostream>
using namespace std;
template <typename T>
class BitList {
   private:
   T value;
   static int objectCount;  // 
   public:
   BitList () : vslur(0){
    value=0;
    objectCount++
   }
   BitList (T v){
    value=v;
    objectCount++
   }
   BitList (const BitList<T>& other){
    value= other.value;
    objectCount++
   }
   ~BitList(){
    objectCount--;
   }
   static int gitCount (){
    return objectCount;
   }
   BitList operator & (const BitList<T> &other ) const{
    return BitList (value& other.value)
   }   BitList operator | (const BitList<T> &other ) const{
    return BitList (value| other.value)-
   }
   BitList& operator&= (const BitList<T> &other){
    value &= other.value;
    return *this;
   }
   BitList& operator|= (const BitList<T> &other){
    value |= other.value;
    return *this;
   }
   BitList operator &&(const BitList<T>& other )const{
    return value  && other.value;
   }
   BitList operator ||(const BitList<T>& other )const{
    return value != 0 ||other.value !=0;
   }
   BitList Intersection (const BitList<T> &other ) const{
    return BitList (value& other.value)
   }
   void setAll(){
      value =~ T(0);
      value = -1;
   }
   void clearAll(){
        value =0;
   }
   void resetBit(int index){
       checkIndex(index);
       value &= ~(1<< index)
   }
   void setBit(index){
        checkIndex(index);
       value |=(1<< index)
   }
   void countSetBits(){
       int count =0;
       T temp = value;
       while ( temp != 0){
        count += temp & T(1);
        temp >> =1;
       } 
       return count;
   }
   bool isEmpty()const{
    return value ==0;
   }
   getValue()const {
    return value;
   }
}