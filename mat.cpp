#include "mat.hpp"
// hours wasted: 36

namespace ariel
{

    void check_errors(int width, int height, char first_char, char second_char)
    {
        // according to demo file line 36 mat size is always odd
        if ((width * height) % 2 == 0)
        {
            throw std::invalid_argument("Mat size is always odd");
        }
        const int mincar = 33;
        const int maxchar = 126;
        if (first_char < mincar || first_char > maxchar || second_char < mincar || second_char > maxchar)
        {
            throw std::invalid_argument("dont use chars that cannot be printed ");
        }
        if (width == 0 || height == 0)
        {
            throw std::invalid_argument("width / height cannot be zero ");
        }
        if (width < 0 || height < 0)
        {
            throw std::invalid_argument("width / height cannot be negative ");
        }
    }

    std::string mat(int width, int height, char first_char, char second_char)
    {
        check_errors(width, height, first_char, second_char);

        /* make the pattern  according to algorithm
            b,a,c,d=input().split()
            g=range
            a,b=int(a),int(b)
            r=[[d]*b for i in g(a)]
            x=y=0
            while x<b/2or y<a/2:
             for i in g(x,a-x):r[i][y]=r[i][b-1-y]=c
             for j in g(y,b-y):r[x][j]=r[a-1-x][j]=c
             x+=2;
            y += 2
            print('\n'.join(map(''.join, r)))
        */
        // https://stackoverflow.com/questions/27370480/how-to-initialize-an-stdstring-with-a-length
        // i talked to Erel and he recomanded me to do so
        std::string str(width * height, second_char);

        int b = width;
        int a = height;
        int x = 0;
        int y = 0;
        while (x <= (b / 2) || y <= (a / 2))
        {
            for (size_t i = x; i < (a - x) && (a - x) > 0; ++i)
            {
                // because of test 7 21 i had to add this if statments and also the second statment
                if ((((a * b) - 1 - ((i * width) + y) % width) >= (width / 2)) && ((((a * b) - 1 - ((i * width) + y) % width) % 2) == 0))
                {
                    str[(a * b) - 1 - ((i * width) + y)] = first_char;
                }
                if (((((i * width) + y) % width) <= (width / 2)) && (((((i * width) + y) % width) % 2) == 0))
                {
                    str[(i * width) + y] = first_char;
                }
            }

            for (size_t j = y; j < (b - y) && (b - y) > 0; ++j)
            {
                if (x < a && j < b)
                {
                    str[(x * width) + j] = first_char;
                    str[(a * b) - 1 - ((x * width) + j)] = first_char;
                }
            }
            x += 2;
            y += 2;
        }

        // concat an output string with '\n' for human visualization :)
        std::string output;
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                output += str[i * width + j];
            }
            output += '\n';
        }

        return output;
    }

}
