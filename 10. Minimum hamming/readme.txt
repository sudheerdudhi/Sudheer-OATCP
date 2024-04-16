1. Initialize Variables:

2. totalDistance: Initialize a variable to store the total Hamming distance.
n: Get the size of the input vector nums.
Iterate through Each Bit Position:

3. Iterate from the least significant bit (LSB) to the most significant bit (MSB) position (0 to 31 assuming 32-bit integers).
Count Ones and Zeros at Each Bit Position:

4. For each bit position, iterate through all integers in the array nums.
Count the number of ones at that bit position by checking the bit using bitwise AND operation with 1 ((nums[j] >> i) & 1). Increment a counter (countOnes) for each integer having a one at that bit position.
Calculate Hamming Distance Contribution:

5. For each bit position, calculate the Hamming distance contribution.
The contribution is the count of ones multiplied by the count of zeros at that bit position (countOnes * (n - countOnes)).
Add this contribution to the total distance.
Return Total Hamming Distance:

6. nce all bit positions are processed, return the total Hamming distance.