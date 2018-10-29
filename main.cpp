/*
	Main.CPP
	David Gurevich
	
	CCC 2018 - Senior 1 Problem - Vornoi Villages
	-------
	In the country of Voronoi, there are N villages, located at distinct points on a straight road. Each
	of these villages will be represented by an integer position along this road.
	
	Each village defines its neighbourhood as all points along the road which are closer to it than
	to any other village. A point which is equally close to two distinct villages A and B is in the
	neighbourhood of A and also in the neighbourhood of B.
	
	Each neighbourhood has a size which is the difference between the minimum (leftmost) point in
	its neighbourhood and the maximum (rightmost) point in its neighbourhood.
	
	The neighbourhoods of the leftmost and rightmost villages are defined to be of infinite size, while
	all other neighbourhoods are finite in size.
	
	Determine the smallest size of any of the neighbourhoods (with exactly 1 digit after the decimal
	point).
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int numOfVillages = 0;
	std::cin >> numOfVillages;

	std::vector<double> V(0);
	std::vector<double> distances(0);

	for (int i = 0; i < numOfVillages; i++) {
		int newVillage = 0;
		std::cin >> newVillage;
		V.push_back(newVillage);
	}

	std::sort(V.begin(), V.end());

	for (int j = 1; j < numOfVillages - 1; j++) {
		double distance = ((V[j + 1] - V[j]) / 2 + (V[j] - V[j - 1]) / 2);
		distances.push_back(distance);
	}

	std::sort(distances.begin(), distances.end());

	printf("%.1f", distances[0]);

	return 0;
}
