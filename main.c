/*
-------------------------------------------------------------------------------------
  EFI PATSARI  --   Lane - Emden equation solver
Expressions used can be found in section 3.3 in the book
"Black Holes, White Dwarfs and Neutron Stars: The Physics of Compact Objects",
 by S.L. Shapiro and S.A. Teukolsky.
 ------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//----------------------------------------------------------------------------------

int main()
{

// variables declaration x = xi, y = theta, z = dtheta/dxi

      double x, y, z ;
      double n;
      double k1, k2, k3, k4, l1, l2, l3, l4, a, b, c;
      double h=0.01;
//----------------------------------------------------------------------------------

//  Value of the polytropic index. Should be in the range 0-3.
         n=1.5;
//----------------------------------------------------------------------------------
    FILE *f = fopen("n=.txt", "w");
        if (f == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }
//----------------------------------------------------------------------------------

//       Initial conditions
            y = 1.0;
            z = 0.0;
//----------------------------------------------------------------------------------

//       Runge-Kutta integration

             while(y>=0)
            {
        for(x=0.015 ; x<= 8.0 ; x=x+h)
        {
            k1 = -h*(2.0*z/(x+h) + pow(y,n));
            l1 = h*z;

            a = y +l1/2.0;


            k2 = -h*(2.0*(z+k1/2.0)/(x+h/2.0) + pow(a,n));
            l2 = h*(z+(k1/2.0));

            b = y +l2;


            k3 = -h*(2.0*(z+k2/2.0)/(x+h/2.0) + pow(b,n));
            l3 = h*(z+(k2/2.0));


            c = y + l3;

            k4 =-h*(2.0*(z+k3)/(x+h) + pow(c,n));
            l4= h*(z+k3);


     z = z + k1/6.0 + k2/3.0 + k3/3.0 +k4/6.0;
     y = y + l1/6.0 + l2/3.0 + l3/3.0 +l4/6.0;


        printf("\n %lf   %lf \n", x, y);
        fprintf(f," %le  %le \n", x, y);

            }

        };
//----------------------------------------------------------------------------------

fclose(f);
system("pause");
return 0;
}
