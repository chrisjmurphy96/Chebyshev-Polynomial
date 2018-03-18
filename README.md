# Chebyshev-Polynomial
Made as a homework assignment for Numerical Modelling.

To compile this project I have provided a makefile.

Generates the Chebyshev nodes for a polynomial of degree n and then uses those points and a Newton divided difference table to generate the corresponding polynomial of the form ax+b(x^2)+c(x^3)... = y. Takes the number of nodes to be generated and a text file as arguments.
If you wish to see the code in action ./driver 11 input_dataset3.txt will provide output for a Chebyshev polynomial with 11 nodes based on the data provided in input_dataset3.txt.

If desired you can run Doxygen on driver.cpp. The project includes Doxygen style comments and a Doxygen formatting file for easier readability.
