//travelling salesman problem 
//a person is there to visit a city 
//he wants to move 'n' places of the city
//we have given the distance between two nodes
//our jobs is to design a algo to give the optimal path in travelling to the city

#include<iostream>
using namespace std;
int main(){
    int number_of_nodes,i,j,small,index = 1,index1 = 0,path_cost = 0,store;
    cin>>number_of_nodes;
    store = number_of_nodes - 1;

    //declaring an array to fill it with the cost of travelling 
    //between the two nodes
    int distance[number_of_nodes][number_of_nodes] = {0};

    //containter to store the path
    int path_movement[number_of_nodes];

    //filling the array with the cost
    cout<<"enter the cost of travelling between two nodes of cities"<<endl;
    for(i=1;i<=number_of_nodes;i++){
        for(j=i;j<=number_of_nodes;j++){
            if(j==i)distance[i][j] = 0;
            else{
                cout<<"node:"<<i<<" to node:"<< j<<" = ";
                cin>>distance[i][j];
                distance[j][i] = distance[i][j];
            }
        }
    }
    i=1;
    while(store--){   
        small = 999;
        for(j=2;j<=number_of_nodes;j++){
            //we have to pick the smallest cost of the travelling 
            //in travelling between two nodes
            if(i!=j && distance[i][j] < small){
                small = distance[i][j];
                distance[j][i] = 1000;
                index = j;
            }
            }
        path_movement[index1++] = index;
        path_cost += small;
        i = index;
    }

    //distance for the last path
    path_cost += distance[index][1];
    path_movement[index1++] = 1;


    //printing the result
    cout<<"optimal path is: 1->";
    for(i=0;i<index1;i++)cout<<path_movement[i]<<"->";

    cout<<"total cost to move is:"<<path_cost<<endl;

    return 0;
}

