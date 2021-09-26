﻿#include <iostream>
#include <fstream>

int main()
{
    double s_matrix[4][4];
    double ad_matrix[4][4];
    int basis[3] = { 1 , 2, 3 };
    int free[3] = { 4, 5, 6 };
    double min = -1;
    std::ifstream in("input.txt");
    for (int i = 0; i < 3; ++i)
        in >> s_matrix[3][i + 1];
    
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            in >> s_matrix[i][j + 1];
        }
    for (int i = 0; i < 3; ++i)
        in >> s_matrix[i][0];
    s_matrix[3][0] = 0;
    std::cout << "   s0  ";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "x" << basis[i] << "  ";
    }
    std::cout << "\n";
    for (int i = 0; i < 4; ++i)
    {
        if (i <=2) std::cout << "x" << free[i] << "  ";
        else std::cout << "F   ";
        for (int j = 0; j < 4; ++j)
        {
            std::cout << s_matrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    in.close();
    bool f = true;
    int perm_col, perm_str;
    while (f)
    {
        perm_str = -1;
        perm_col = -1;

        for (int i = 0; i < 3; ++i)
        {
            if (s_matrix[i][0] < 0)
            {
                perm_str = i;
                break;
            }
        }
        if (perm_str >= 0)
        {
            for (int i = 1; i < 4; ++i)
            {
                if (s_matrix[perm_str][i] < 0)
                {
                    perm_col = i;
                    break;
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                if (((s_matrix[i][0] / s_matrix[i][perm_col]) >= 0) && ((min < 0) || (s_matrix[i][0] / s_matrix[i][perm_col] < min)))
                {
                    min = s_matrix[i][0] / s_matrix[i][perm_col];
                    perm_str = i;
                }
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i != perm_str && j != perm_col)
                        ad_matrix[i][j] = s_matrix[i][j] - s_matrix[i][perm_col] * s_matrix[perm_str][j] / s_matrix[perm_str][perm_col];
                    else if (i != perm_str)
                        ad_matrix[i][j] = -1 * s_matrix[i][j] / s_matrix[perm_str][perm_col];
                    else if (j != perm_col)
                        ad_matrix[i][j] = s_matrix[i][j] / s_matrix[perm_str][perm_col];
                    else
                        ad_matrix[i][j] = 1 / s_matrix[i][j];
                }
            }
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    s_matrix[i][j] = ad_matrix[i][j];
            std::swap(basis[perm_col - 1], free[perm_str]);
            std::cout << "   s0  ";
            for (int i = 0; i < 3; i++)
            {
                std::cout << "x" << basis[i] << "  ";
            }
            std::cout << "\n";
            for (int i = 0; i < 4; ++i)
            {
                if (i <= 2) std::cout << "x" << free[i] << "  ";
                else std::cout << "F   ";
                for (int j = 0; j < 4; ++j)
                {
                    std::cout << s_matrix[i][j] << "   ";
                }
                std::cout << std::endl;
            }
        }
        else f = false;
    }
    f = true;
    bool unlim = false;
    while (f && !unlim)
    {
        perm_col = -1;
        min = -1;
        for (int i = 1; i < 4; ++i)
        {
            if (s_matrix[3][i] > 0)
            {
                perm_col = i;
                break;
            }
        }
        if (perm_col > 0)
        {
            unlim = true;
            for (int i = 0 ; i < 3; ++i)
                if (s_matrix[i][perm_col] > 0)
                {
                    unlim = false;
                    break;
                }
            for (int i = 0; i < 3; ++i)
            {
                if (((s_matrix[i][0] / s_matrix[i][perm_col]) >= 0) && ((min < 0) || (s_matrix[i][0] / s_matrix[i][perm_col] < min)))
                {
                    min = s_matrix[i][0] / s_matrix[i][perm_col];
                    perm_str = i;
                }
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (i != perm_str && j != perm_col)
                        ad_matrix[i][j] = s_matrix[i][j] - s_matrix[i][perm_col] * s_matrix[perm_str][j] / s_matrix[perm_str][perm_col];
                    else if (i != perm_str)
                        ad_matrix[i][j] = -1 * s_matrix[i][j] / s_matrix[perm_str][perm_col];
                    else if (j != perm_col)
                        ad_matrix[i][j] = s_matrix[i][j] / s_matrix[perm_str][perm_col];
                    else
                        ad_matrix[i][j] = 1 / s_matrix[i][j];
                }
            }
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    s_matrix[i][j] = ad_matrix[i][j];
            std::swap(basis[perm_col - 1], free[perm_str]);
            std::cout << "   s0  ";
            for (int i = 0; i < 3; i++)
            {
                std::cout << "x" << basis[i] << "  ";
            }
            std::cout << "\n";
            for (int i = 0; i < 4; ++i)
            {
                if (i <= 2) std::cout << "x" << free[i] << "  ";
                else std::cout << "F   ";
                for (int j = 0; j < 4; ++j)
                {
                    std::cout << s_matrix[i][j] << "   ";
                }
                std::cout << std::endl;
            }
        }
        else f = false;
    }
    std::cout << std::endl;
    if (unlim)
    {
        std::cout << "Function is unlimitted\n";
    }
    /*
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            std::cout << s_matrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < 3; ++i) std::cout << basis[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < 3; ++i) std::cout << free[i] << " ";
    */
    else
    {
        std::cout << "\nSolution:\n";
        std::cout << "F = " << s_matrix[3][0] * (-1) << "\n";
        for (int i = 0; i < 3; ++i)
        {
            std::cout << "x" << basis[i] << " = 0\n";
        }
        for (int i = 0; i < 3; ++i)
        {
            std::cout << "x" << free[i] << " = " << s_matrix[i][0] << "\n";
        }
    }
    return 0;
}

