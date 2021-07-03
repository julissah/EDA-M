#include <bits/stdc++.h>
using namespace std;
 
void lectura();
vector<string> split(string str, char pattern);
void swap(int *xp, int *yp);
void selectionSort(int arr[], int n);
void printArray(int arr[], int size);
 
int main(){
    lectura();
    
    system("pause");
    return 0;
}


void lectura(){

    ifstream archivo;
    string texto; 
    char pattern=',';
    unsigned t0, t1;
   
    vector<string> results;

    archivo.open("datos100000.txt",ios::in);
    if(archivo.fail()){
        cout<<"No se pudo abrir ela rchivo";
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
    selectionSort(arr,n);
    cout<<"Lista Ordenada por Algoritmo Selection_Sort\n";
    printArray(arr,n);
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


 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 

 
