#include <iostream>

void print_rectangle(int h, int b = -1)

{

    if (b == -1)
    {

        b = h;
    }

    for (int i = 0; i < b; i++)
    {
        for (int r = 0; r < h; r++)
        {
            std::cout << "X ";
        }

        std::cout << '\n';
    }

    std::cout << '\n';
    // return 0;
}

int main()
{
    std::cout << "x = 2, y = 5: " << std::endl;
    print_rectangle(2, 5);

    std::cout << "x = 3, y = 3: " << std::endl;
    print_rectangle(3, 3);

    std::cout << "x = 4: " << std::endl;
    print_rectangle(4);

    return 0;
}
