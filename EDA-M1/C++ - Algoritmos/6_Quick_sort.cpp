#include <bits/stdc++.h>
using namespace std;
 
void lectura();
vector<string> split(string str, char pattern);
void swap(int *xp, int *yp);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);
int partition (int arr[], int low, int high);
 
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
    quickSort(arr,0,n-1);
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


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 

 

