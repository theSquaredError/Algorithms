/*
Problem - Given of array A of n points, write a program 
			to compute the convex hull of A using Graham's scan algorithm
			and stack data structure.

convex hull of S is the smallest convex polygon that contains all the points of S
------------

link to readmore = http://www.dcs.gla.ac.uk/~pat/52233/slides/Hull1x1.pdf
*/



/************ Algorithm for finding convex hull of given points *******************/
/*

Input: A set of n points

1. Choose a point p1 s.t whose y-coordinate is minimum - theta(n)
2. Sort all the points using angles made by x-axis.    - theta(nlogn)
3. S.push(p1), s.push(p2)

4. for(i=3 to n){
		
		while(orientation(s.second.top(), s.top(),p_i) == right_turn){
			s.pop()  -- if it is a right turn then we discard it
		}
		s.push(P_i)
	}
	all the elements remaining in the stack are the elements of the convex hull

*/
/************************************* end ****************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;

double findAngle(pair<int, int> p, pair<int,int> q){
    double slope = (double)(q.second - p.second)/(q.first - p.first);
    double angle = atan(slope);
    return angle;
}


int orientation(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
	/*
		Input: Takes three points p1, p2, p3 
		Output: Orientation of line segement p1,p2 and p2,p3
				Returns : 1 (counter clockwise)(left turn) [sigma < tow]
						  2 (clockwise) (right turn)        [sigma > tow]
						  3 (collinear) (left turn)         [sigma == tow]

		Method: 
				slope of segment (p1,p2) = sigma
				slope of segment (p2,p3) = tow
	
	*/

	// double sigma = (double)(p2.second - p1.second)/(p2.first - p1.first);
	// double tow = (double)(p3.second - p2.second)/(p2.first - p1.first);

	// if(sigma < tow) //left turn
	// 	return 1; 
	// else if(sigma > tow) //right turn
	// 	return 2;
	// else 			//collinear
	// 	return 3;

	int val = (p2.second - p1.second)*(p3.first- p2.first) -
				(p2.first - p1.first) * (p3.second - p2.second);

	if(val == 0) return 0;
	return (val>0)?1:2; //clock or anticlock
}

int anchorPoint(vector<pair<int, int>> points){

	pair<int, int> anchor_point = points[0];
	int position;
	for(int i =1; i<points.size(); i++){
		if(points[i].second<anchor_point.second){
			anchor_point = points[i];
			position = i;
		}
	}

	return position;
}

pair<int, int> g_anchor_points;

bool comparator(pair<int, int> p, pair<int, int> q){
	return findAngle(g_anchor_points,p)<findAngle(g_anchor_points, q);
}

pair<int,int> secondTop(stack<pair<int,int>> S){
	pair<int,int> top = S.top();
	S.pop();
	pair<int,int> second_top = S.top();
	S.push(top);
	return second_top;
}

stack<pair<int,int>> convexHull(vector<pair<int, int>> points){
		
		// finding anchor point
		int position = anchorPoint(points); 
		pair<int, int> anchor_point = points[position];
		g_anchor_points = anchor_point;
		// cout<<"anchor_point "<<anchor_point.first<<" "<<anchor_point.second<<endl;

		//removing anchor point from array
		for (auto i = points.begin(); i != points.end(); ++i) {
	        if (*i  == anchor_point) {
	            points.erase(i);
	            i--;
	        }
    	}

		//Sorting points wrt to angle made by segment(p,q) q- remaining points with x-axis
		sort(points.begin(), points.end(), comparator);


		// Now I have sorted points wrt angle
		
		// 4 step of the algorithm
		stack<pair<int, int>> S;
		S.push(anchor_point);
		S.push(points[0]);
	
		for(int i = 1;i<points.size();i++){
			while(S.size()>1 and orientation(secondTop(S),S.top(),points[i])!=2){ //if right turn
				S.pop();
			} 
			S.push(points[i]);
		}

		return S;
}




int main(){

	vector<pair<int, int>> points = {
									 {0,3},
									 {1,1},
									 {2,2},
									 {4,4},
									 {0,0},
									 {1,2},
									 {3,1},
									 {3,3}
											};

	stack<pair<int, int>> convex_hull = convexHull(points);

	while(!convex_hull.empty()) {
        cout << convex_hull.top().first<<" "<<convex_hull.top().second<<endl;
        convex_hull.pop();
    }

	return 0;
}