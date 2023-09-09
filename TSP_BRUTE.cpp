/**
 * Implementation of Homework 6 assigned by Erin Keith for CS 302.
 * 
 * @file       TSP_BRUTE.h
 * @brief      innefficient TSP solver through full path analysis
 * @author     Robert Bothne
 * @date       4/28/21
 * 
 * note: similar to djirka program for cs365.
 */
#include <vector> 
#include <algorithm>  
#include <iostream>
using namespace std;
#define V 5

void TSP_SOLVER(float plot[][V],int source);

int main(){
    int source = 0;
    float plot[][V] = { 
        { 0, 218.4, 518.2, 704.2, 439.1 }, //1 Reno
        { 218.4, 0, 735.9, 807.7, 568.8 }, // 2 San Fran
        { 518.2, 735.9, 0, 829.3, 421.2 }, // 3 Salt Lake
        { 704.2, 807.7, 829.3, 0, 1111.4 }, // 4 Seattle
        { 439.1, 568.8, 421.2, 1111.4, 0 }}; //5 Las Vegas

    TSP_SOLVER(plot, source);

   return 0;
}

void TSP_SOLVER(float plot[][V], int source){
   vector<int> point;
   int path[V],temp[V];
   for (int i = 0; i < V; i++){ //add all elements to vector other than source point
        if (i != source){
           point.push_back(i);
        }
   }
   float shortestP = INT_MAX; //set shortestP infinitely High to force re-evaluation on first pass
   do {
       float currentCost = 0; //total cost of trip
       int k = source; 
       cout<<k+1<<", "; //start
       for (int i = 0; i < point.size(); i++) { 
           currentCost += plot[k][point[i]];
           k = point[i];
           temp[i]=k;
       }

       currentCost += plot[k][source];

       for(int i = 0; i < V-1; i++){ //path analysis display
           if(i==V-2){
                cout<<temp[i]+1<< " TRAVERSED" << endl; //end of path
           } 
           else{
                cout<<temp[i]+1<<", ";
           } 
       }
       shortestP = min(shortestP, currentCost); //shortest = lesser of current or shortest
       if(shortestP==currentCost){ 
           for(int i = 0; i < V-1; i++){
               path[i]=temp[i]; 
           }
       }
   } while (next_permutation(point.begin(), point.end())); //all permutations are cleared

   cout<<source+1<<", "; // reno

   for(int i = 0; i < V-1; i++){ //display shortest path omitting source
       if(i==V-2){
            cout<<path[i]+1<<", "<<source+1<< " SHORTEST PATH" << endl;
       } 
       else {
           cout<<path[i]+1<<", ";
     }
   }
   float miles =  shortestP;
   cout <<endl << "MILES:" << miles << endl << "COST:" << miles*40 << "$" << endl<< endl;   
}