#include<iostream>
#include<string>
using namespace std;
int main(){
    string sentence;
int words=0;
cout <<"Enter a sentence : ";
getline (cin,sentence);

for (int i =0; i <sentence.length(); i++){
    if(sentence[i] !=' ' && (i==0 || sentence[i-1]==' ' ) ) {
        words++;
    }

}

cout << " number of words: "<< words<<endl;
return 0;

}
