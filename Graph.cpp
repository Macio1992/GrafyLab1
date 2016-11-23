#include "Graph.h"
#include <iostream>

Graph::Graph(int x){
	
	size = x;
		
	graph = new int*[size];
	for(int i = 0; i < size; i++)
		graph[i] = new int[size];
		
	zeroGraph(graph);
	
}

Graph::~Graph(){
	
	for (int i = 0; i < size ; i++)
		delete [] graph[i];
	delete [] graph;
	
}

void Graph::wypisz(){
	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << graph[i][j]<<" ";
		}
		cout <<"\n";
	}
	cout <<"\n";
	
}

void Graph::zeroGraph(int **tab){
	
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			tab[i][j] = 0;
	
}

void Graph::fillTheMatrix(){
	ifstream ifile;
	ifile.open("data.txt");
	int a, b;
	while(ifile >> a >> b){
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	ifile.close();
}

bool Graph::checkIfEdgeExists(int x, int y){
	if(graph[x][y] == 1 && graph[y][x] == 1)
		return true;
	else return false;
}

void Graph::removeEdge(){
	
	int x,y;
	do {
		cout <<"Podaj wspolrzedne krawedzi ktora chcesz usunac:"<<endl;
		cin >> x >> y;
	} while(!checkIfEdgeExists(x, y));
							
	graph[x][y] = 0;
	graph[y][x] = 0;
	
	cout << "Krawedz "<<x<<" - "<<y<<" usunieto"<<endl;
}

void Graph::addEdge(){
	
	int x,y;
	do {
		cout <<"Podaj krawedz ktora chcesz dodac:"<<endl;
		cin >> x >> y;
	} while(!((x >= 0 && x <= size) && (y >= 0 && y <= size)));
							
	graph[x][y] = 1;
	graph[y][x] = 1;
	
	cout << "Krawedz "<<x<<" - "<<y<<" dodano"<<endl;
	
}

void Graph::addVertex(){
	size = size + 1;
	
	int **tmp = 0;
	tmp = new int*[size];
	
	for(int i = 0; i < size; i++)
		tmp[i] = new int[size];
	
	zeroGraph(tmp);
	
	for(int i = 0; i < size-1; i++)
		for(int j = 0; j < size-1; j++)
			tmp[i][j] = graph[i][j];
	
	graph = new int*[size];
	
	for(int i = 0; i < size; i++)
		graph[i] = new int[size];
		
	zeroGraph(graph);
	
	for(int i = 0; i < size-1; i++)
		for(int j = 0; j < size-1; j++)
			graph[i][j] = tmp[i][j];
			
	for (int i = 0; i < size ; i++)
		delete [] tmp[i];
	cout <<"Dodano wierzcholek nr "<<size<<endl;
}

void Graph::removeVertex(){
	int w;
	do{
		cout <<"Podaj nr wierzcholka"<<endl;
		cin >> w;
	} while(!(w >= 0 && w < size));
			
	for(int j = 0; j < size; j++)
	graph[w][j] = 0;

	cout <<"Wierzcholek nr "<<w<<" zostal usuniety"<<endl;
	wypisz();
}

int Graph::returnDegreeOfVertex(int x){
	
	int licznik = 0;
	
	for(int i = 0; i < size; i++)
		if(i == x){
			for(int j = 0; j < size; j++)
				if(graph[i][j] == 1) licznik++;
	}
	
	return licznik;
}

void Graph::maxAndMinDegree(){
	
	int max = 0, min = 0;
	int licznik = 0;
						
		for(int i = 0; i < size; i++){
			min = licznik;
			licznik = 0;
			for(int j = 0; j < size; j++){
				if(graph[i][j] == 1) licznik++;
		}
							
		if(licznik > max) max = licznik;
		if(licznik < min) min = licznik;
	}
	
	cout << "Maksymalny stopien: "<<max<<"\nMinimalny stopien : "<<min<<endl;
	
}

void Graph::evenAndOddDegrees(){
	
	int even = 0, odd = 0, licznik = 0;
	for(int i = 0; i < size; i++){
		licznik = 0;
		for(int j = 0; j < size; j++){
			if(graph[i][j] == 1) licznik++;
		}
		if(licznik % 2 == 0) even++;
		else odd++;
	}
	cout <<"Iloscc parzystych stopni : "<<even<<", Iloscc nieparzystych stopni : == "<<odd<<"\n";
	
}

int Graph::checkIfHasCycle(){
	int **array2D = 0;
	array2D = new int*[size];
	
	for(int i = 0; i < size; i++)
		array2D[i] = new int[size];
	
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			array2D[i][j] = 0;

	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			for(int k = 0; k < size; k++)
				array2D[i][j] += graph[i][k]*graph[k][j];
	
	int **array2D3 = 0;
	array2D3 = new int*[size];
	
	for(int i = 0; i < size; i++)
		array2D3[i] = new int[size];
		
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			array2D3[i][j] = 0;
			
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			for(int k = 0; k < size; k++)
				array2D3[i][j] += array2D[i][k]*graph[k][j];
	
	int slad = 0;
	for(int i = 0; i < size; i++)
		slad += array2D3[i][i];
	
	for (int i = 0; i < size ; i++)
		delete [] array2D[i];
	
	for (int i = 0; i < size ; i++)
		delete [] array2D3[i];
	
	return slad;
}

void Graph::degreeVertexSequence(){
	
	int *sequence = new int[size];
	int licznik = 0;
				
	for(int i = 0; i < size; i++){
		licznik = 0;
		for(int j = 0; j < size; j++){
			if(graph[i][j] == 1) licznik++;
		}
		sequence[i] = licznik;
	}
			
	for( int i = 0; i < size; i++ )
    {
        for( int j = 0; j < size - 1; j++ )
        {
            if( sequence[ j ] < sequence[ j + 1 ] )
                 swap( sequence[ j ], sequence[ j + 1 ] );
        }
    }
				
	cout <<"Ciag wierzcholkow:\n";
	for(int i = 0; i < size; i++)
		cout <<sequence[i]<<" ";
	cout <<"\n";
				
	delete [] sequence;
}

bool Graph::checkIfSequenceGraphical(int *sequence, int length){
	int smin, s, flag, graficzny;
	
	graficzny=1;

	s=0;
	for (int i=0; i<length; i++) 
		s+=sequence[i];
	if ((s%2)!=0)
		graficzny=0;
	else{
		flag=1;
		while (flag==1) {
			flag=0;
			for (int i=0; i<length-1; i++)
				if (sequence[i]<sequence[i+1]) {
					s=sequence[i];
					sequence[i]=sequence[i+1];
					sequence[i+1]=s;
					flag=1;
				}
		}
	}
	
	int j=0;
	while ((graficzny==1) && (j<length-1)){
		s=0;
		for (int i=0; i<=j; i++) s+=sequence[i];
			smin=0;
		for (int i=0; i<length; i++)
			if ((j+1)<sequence[i]) 
				smin=smin+(j+1);
			else 
				smin+=sequence[i];
		if (s>(j*(j+1)+smin)) 
			graficzny=0;
		else 
			j++;
	}
	
	if (graficzny==1) 
		return true;
	else 
		return false;
}
