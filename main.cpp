#include <iostream>
#include "Graph.h"

/*
	Zaimplementuj odpowiednie struktury danych i procedury pozwalaj¹ce na przechowywanie
	grafu w postaci macierzy s¹siedztwa oraz:
	a) dodanie/usuniêcie krawêdzi/wierzcho³ka; (1 pkt)
	b) wyznaczenie stopnia wierzcho³ka oraz minimalnego i maksymalnego stopnia grafu; (1 pkt)
	c) wyznaczenie, ile jest wierzcho³ków stopnia parzystego i nieparzystego; (1 pkt)
	d) wypisanie (posortowanego nierosn¹co) ci¹gu stopni wierzcho³ków w grafie. (1 pkt)

*/

int main(int argc, char** argv) {
	
	int vertexAmount, choice;
	
	do{
		cout <<"Podaj dodatnia ilosc wierzcholkow"<<endl;
		cin >>vertexAmount;
	} while(!(vertexAmount > 0));
	
	Graph graph(vertexAmount);
	graph.fillTheMatrix();
	
	do {
		graph.wypisz();
		
		cout <<"0 - Dodaj / Usun Wierzcholek lub krawedz"<<endl;
		cout <<"1 - Wyznacz stopien wierzcholka"<<endl;
		cout <<"2 - Wyznacz minimalny i maksymalny stopien grafu"<<endl;
		cout <<"3 - Wyznacz liczbe parzystych i nieparzystych stopni grafu"<<endl;
		cout <<"4 - Sprawdz czy podgraf posiada podgraf C3"<<endl;
		cout <<"5 - Sprawdz czy ciag jest grafowy"<<endl;
		cout <<"7 - END\n";
		
		cin>>choice;
		
		switch(choice){
			case 0:{
				char choiceVE, choiceAR;
				
				cout <<"Krawedz - k\nWierzcholek - w\n";
				cin >>choiceVE;
				
				switch(choiceVE){
					case 'k':{
						
						cout <<"Dodaj - d lub usun - u, krawedz:"<<endl;
						cin >> choiceAR;
						
						switch(choiceAR){
							case 'd':{
								graph.addEdge();
								break;
							}
							case 'u':{
								graph.removeEdge();
								break;
							}
						}
						
						break;
					}
					case 'w':{
						
						cout <<"Dodaj - d lub usun - u, wierzcholek:"<<endl;
						cin >> choiceAR;
						
						switch(choiceAR){
							case 'd':{
								graph.addVertex();
								break;
							}
							case 'u':{
								graph.removeVertex();
								break;
							}
						}
						
						break;
					}
				}
				
				break;
			}
				
			case 1:{
				int vertex;
				do{
					cout<<"Podaj numer wierzcholka:"<<endl;
					cin>>vertex;
				}while(!(vertex >= 0 && vertex < vertexAmount-1));
				
				cout <<"Wierzcholek nr "<<vertex<<" jego stopien : "<<graph.returnDegreeOfVertex(vertex)<<endl;
				
				break;
			}
			case 2:{
				graph.maxAndMinDegree();
				break;
			}
			case 3:{
				graph.evenAndOddDegrees();
				break;
			}
			case 4: {
				if(graph.checkIfHasCycle()==0) cout<<"Graf nie ma cyklu"<<endl;
				else cout <<"Graf ma cykl"<<endl;
				break;
			}
			case 5: {
				graph.degreeVertexSequence();
				break;
			}
			case 6: {
				int length;
				
				do {
					cout <<"Podawaj dlugosc ciagu:"<<endl;
					cin >> length;
				} while(!(length >= 0));
				
				int *sequence = new int[length];
				
				cout <<"Podaj ciag:\n";
				for (int i=0; i<length; i++)
					cin >> sequence[i];
				
				if(graph.checkIfSequenceGraphical(sequence, length))
					cout <<"Ciag jest graficzny"<<endl;
				else
					cout <<"Ciag nie jest graficzny"<<endl;
				
				delete [] sequence;
				
				break;
			}
			default:{
				cout<<"Wpisz numer miedzy 0 a 6"<<endl;
				break;
			}
		};
		
	}while(choice != 7);
	
	return 0;
}
