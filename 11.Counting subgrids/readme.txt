1. Loop through All Possible Top-Left Corners:

2. The algorithm iterates through each cell in the grid, considering each cell as the 
potential top-left corner of a subgrid.Check if the Current Cell is Black:

3. For each cell considered as the top-left corner, the algorithm checks if the cell is 
black (value 0).Loop through All Possible Bottom-Right Corners:

4. If the current cell is black, the algorithm then iterates through all cells to the right 
and below it, considering each cell as a potential bottom-right corner of the subgrid.
Check if All Corners of the Subgrid are Black:

5. For each potential bottom-right corner, the algorithm checks if all four corners of the subgrid 
formed by the top-left and bottom-right corners are black (value 0).Count the Subgrids:

6. If all four corners of the subgrid are black, the algorithm increments the count of subgrids.
Return the Count:

7. After checking all possible subgrids formed by each cell as the top-left corner, the algorithm returns the total count of subgrids with all black corners.