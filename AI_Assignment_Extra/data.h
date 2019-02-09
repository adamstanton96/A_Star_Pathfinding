#pragma once

#include <vector>


namespace data{

// auxiliary types
struct location
{
	float y, x; // lat, long
};
typedef float cost;

typedef std::pair<int, int> path;

typedef std::pair<int, int> Vector;





//Specify our data:

//The identifier for each node.
enum nodes {	n0, n1, n2, n3, n4, n5, n6, n7, n8, n9,
				n10, n11, n12, n13, n14, n15, n16, n17, n18, n19,
				n20, n21, n22, n23, n24, n25, n26, n27, n28, n29,
				n30, n31, n32, n33, n34, n35, n36, n37, n38, n39,
				n40, n41, n42, n43, n44, n45, n46, n47, n48, n49,
				n50, n51, n52, n53, n54, n55, n56, n57, n58, n59,
				n60, n61, n62, n63,
				N,
};

//The displayable names of each node (In our case a character representation of the node number).
int name[] = {	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
				10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
				20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 
				30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 
				40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 
				50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 
				60, 61, 62, 63 };

//The location of each node in space stored as two integer values representing: /{latitude,longitude}.
location locations[] = {

	{ 45,0 },{ 330,0 },{ 150,30 },{ 120,45 },{ 345,45 },{ 0,60 },{ 465,60 },{ 60,105 },{ 120,105 },{ 210,120 },				//Nodes 0-9
	{ 300,120 },{ 165,135 },{ 450,135 },{ 45,150 },{ 570,150 },{ 45,165 },{ 315,180 },{ 90,210 },{ 555,210 },{ 180,225 },	//Nodes 10-19
	{ 120,255 },{ 375,255 },{ 240,270 },{ 300,285 },{ 360,285 },{ 45,300 },{ 540,300 },{ 270,330 },{ 225,345 },{ 345,345 },	//Nodes 20-29
	{ 555,345 },{ 90,375 },{ 390,375 },{ 240,405 },{ 345,405 },{ 390,405 },{ 120,420 },{ 360,420 },{ 375,420 },{ 285,450 },	//Nodes 30-39	
	{ 420,450 },{ 180,465 },{ 210,465 },{ 420,465 },{ 495,465 },{ 30,480 },{ 150,480 },{ 15,495 },{ 300,495 },{ 495,495 },	//Nodes 40-49
	{ 45,510 },{ 105,525 },{ 255,525 },{ 450,525 },{ 480,525 },{ 90,540 },{ 225,540 },{ 570,555 },{ 195,570 },{ 450,570 },	//Nodes 50-59	
	{ 480,570 }, { 195,585 },{ 450,585 },{ 585,585 }																		//Nodes 60-63

};

//The edges (pathways) connecting each node in space initialised using: (node1,node2).
path edge_array[] = {
	path(0,5),   path(0,3),
	path(0,7),   path(0,2),
	path(1,4),   path(1,10),
	path(1,6),   path(1,9),
	path(2,3),   path(2,8),
	path(2,11),  path(3,8),
	path(3,7),   path(4,10),
	path(4,6),   path(4,12),
	path(5,7),   path(5,13),
	path(5,15),  path(6,12),
	path(6,14),  path(7,13),
	path(8,11),  path(8,13),
	path(9,11),  path(9,10),
	path(9,19),  path(10,16),
	path(11,19), path(12,14),
	path(12,18), path(13,15),
	path(14,18), path(14,26),
	path(15,17), path(15,20),
	path(16,21), path(16,23),
	path(16,24), path(17,20),
	path(17,19), path(17,25),
	path(18,26), path(18,30),
	path(19,20), path(20,25),
	path(21,24), path(21,23),
	path(21,29), path(22,23),
	path(22,27), path(22,28),
	path(22,24), path(23,27),
	path(24,29), path(25,31),
	path(25,36), path(26,30),
	path(26,32), path(27,28),
	path(27,29), path(28,33),
	path(28,29), path(30,44),
	path(30,49), path(31,36),
	path(31,45), path(31,46),
	path(32,35), path(32,38),
	path(32,34), path(33,39),
	path(33,42), path(33,41),
	path(34,37), path(34,38),
	path(34,35), path(35,38),
	path(35,37), path(36,46),
	path(36,41), path(37,38),
	path(37,40), path(39,48),
	path(39,42),
	path(39,52), path(40,43),
	path(40,44), path(40,53),
	path(41,42), path(41,46),
	path(42,46), path(43,53),
	path(43,44), path(43,49),
	path(44,49), path(45,47),
	path(45,50), path(45,55),
	path(47,50), path(47,55),
	path(47,51), path(48,52),
	path(48,56), path(48,58),
	path(49,54), path(50,55),
	path(50,51), path(51,55),
	path(51,58), path(52,56),
	path(52,58), path(53,54),
	path(53,59), path(54,60),
	path(54,59),
	path(56,58), path(56,61),
	path(57,63), path(57,60),
	path(57,59), path(57,62),
	path(59,62), path(60,62),
	path(60,63), path(61,62),
	path(61,63)
};


// Arbitrary values used to represent travel time along each pathway. Used in determining the shortest route.
cost weights[] = {
	75,87,106,109,47,123,147,169,33,80,106,60,
	84,87,120,138,75,100,114,76,138,47,54,87,47,90,
	109,61,91,120,129,15,61,152,63,117,96,106,114,54,91,100,91,135,
	67,87,33,80,94,61,67,76,120,54,61,87,141,47,167,47,76,61,120,
	134,161,54,120,120,30,47,54,63,67,84,21,33,45,21,33,67,75,
	15,67,47,76,80,15,76,80,30,33,61,67,75,80,30,21,33,84,
	33,87,94,54,87,129,33,54,61,21,100,33,75,30,45,45,54,
	42,54,33,91,120,123,15,33,106,255,390,
};


}