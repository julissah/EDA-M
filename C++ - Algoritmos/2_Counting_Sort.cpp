#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cstdlib>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

static void countingsort(int Array[], int n) ;
static void PrintArray(int Array[], int n);
vector<string> split(string str, char pattern);

void lectura(){
    ifstream archivo;
    string texto; 
    char pattern=',';
    unsigned t0, t1;
   
    vector<string> results;

    archivo.open("datos1.txt",ios::in);
    if(archivo.fail()){
        cout<<"No se pudo Abrir el Archivo";
        exit(1);
    }

    while (!archivo.eof())
    {
        getline(archivo,texto);
        
    }

   results = split(texto, pattern);
    int arr[results.size()];
    for(int i = 0; i < results.size(); i++){
        //cout<<results[i]<<endl;
        arr[i]=atoi(results[i].c_str());
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    t0=clock();


    countingsort(arr,n);
    cout<<"Lista Ordenada \n";
    PrintArray(arr,n);


	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Tiempo de ejecucion: " << time << endl;
    archivo.close();
}

vector<string> split(string str, char pattern) {
    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;
    
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    return results;
}







// function for counting sort
static void countingsort(int Array[], int n) {
  int max = 0;
  
  // find largest element in the Array
  for (int i=0; i<n; i++) {  
    if(max < Array[i]) {
      max = Array[i];
    } 
  }

  // Create a freq array to store number of occurrences of 
  // each unique elements in the given array 
  int freq[max+1];
  for (int i=0; i<max+1; i++) {  
    freq[i] = 0;
  } 
  for (int i=0; i<n; i++) {  
    freq[Array[i]]++;
  } 
  
  // sort the given array using freq array
  for (int i=0, j=0; i<=max; i++) {  
    while(freq[i]>0) {
      Array[j] = i;
      j++;
      freq[i]--;
    }
  } 
}

// function to print array
static void PrintArray(int Array[], int n) { 
  for (int i=0; i<n; i++) 
    cout<<Array[i]<<" "; 
  cout<<"\n"; 
} 

// test the code
int main (){
  // int MyArray[] = {999,9, 1, 2, 5, 9, 9, 2, 1, 3, 3,5,8,9,2,5,4,5,2,14,4,4,5,2,1,4,88,5,400,1000};
  // int n = sizeof(MyArray) / sizeof(MyArray[0]); 
  // cout<<"Original Array\n";
  // PrintArray(MyArray, n);
  lectura();
  // countingsort(MyArray, n);
  // cout<<"\nSorted Array\n";
  // PrintArray(MyArray, n);
  return 0;
}