#include <iostream>

using namespace std;

void NormalizeCuboid(int data[], int edgeLength)
{
    for (int i = 0; i < 3; i++)
        if (data[i] >= edgeLength / 2)
            data[i] -= data[i + 3];
}

void NormalizeOctalTetrahedron(int data[], int edgeLength)
{
    for (int i = 0; i < 3; i++)
        if (data[i] >= edgeLength / 2)
            data[i] -= data[3];
}

bool inCube(int edgeLength, int data[])
{
    for (int i = 0; i < 3; i++)
        if (data[i] > edgeLength - 1 || data[i] < 0)
            return false;
    return true;
}

long long signed int SumCuboid(int edgeLength, int cube[32][32][32], int data[])
{
    long long signed int sum = 0;
    int tempData_1 = data[1];
    int tempData_0 = data[0];

    int panelBorder = data[5] + data[2];
    int levelBorder = data[3] + data[0];
    int vecticalBorder = data[4] + data[1];

    for (data[2]; data[2] <= panelBorder; data[2]++)
    {
        data[0] = tempData_0;
        for (data[0]; data[0] <= levelBorder; data[0]++)
        {
            data[1] = tempData_1;
            for (data[1]; data[1] <= vecticalBorder; data[1]++)
                if (inCube(edgeLength, data))
                    sum += cube[data[2]][data[1]][data[0]];
        }
    }
    return sum;

}

bool isSphere(int data[], int smallCubedata[])
{
    if ((smallCubedata[0] - data[0]) * (smallCubedata[0] - data[0]) + (smallCubedata[1] - data[1]) * (smallCubedata[1] - data[1]) + (smallCubedata[2] - data[2]) * (smallCubedata[2] - data[2]) <= (data[3] * data[3]))
        return true;
    return false;
}


long long signed int SumOctal(int edgeLength, int cube[32][32][32], int data[], int  smallCubedata[])
{
    long long signed int sum = 0;
    int tempData_1 = smallCubedata[1];
    int tempData_0 = smallCubedata[0];

    int panelBorder = smallCubedata[3] + smallCubedata[2];
    int levelBorder = smallCubedata[3] + smallCubedata[0];
    int vecticalBorder = smallCubedata[3] + smallCubedata[1];

    for (smallCubedata[2]; smallCubedata[2] <= panelBorder; smallCubedata[2]++)
    {
        smallCubedata[0] = tempData_0;
        for (smallCubedata[0]; smallCubedata[0] <= levelBorder; smallCubedata[0]++)
        {
            smallCubedata[1] = tempData_1;
            for (smallCubedata[1]; smallCubedata[1] <= vecticalBorder; smallCubedata[1]++)
                if (inCube(edgeLength, smallCubedata) && isSphere(data, smallCubedata))
                    sum += cube[smallCubedata[2]][smallCubedata[1]][smallCubedata[0]];
        }
    }
    return sum;
}

bool inTriangle(int Xa, int Ya, int Xb, int Yb, int smallCubedata[])
{
    if ((smallCubedata[1] - Ya) * (Xb - Xa) - (Yb - Ya) * (smallCubedata[0] - Xa) >= 0)
        return true;
    return false;
}


long long signed int SumTetrahedron(int edgeLength, int cube[32][32][32], int data[], int  smallCubedata[])
{
    long long signed int sum = 0;
    int tempData_1 = smallCubedata[1];
    int tempData_0 = smallCubedata[0];

    int panelBorder = smallCubedata[3] + smallCubedata[2];
    int levelBorder = smallCubedata[3] + smallCubedata[0];
    int vecticalBorder = smallCubedata[3] + smallCubedata[1];

    for (smallCubedata[2]; smallCubedata[2] <= panelBorder; smallCubedata[2]++)
    {
        smallCubedata[0] = tempData_0;
        for (smallCubedata[0]; smallCubedata[0] <= levelBorder; smallCubedata[0]++)
        {
            smallCubedata[1] = tempData_1;
            for (smallCubedata[1]; smallCubedata[1] <= vecticalBorder; smallCubedata[1]++)
                if (inCube(edgeLength, smallCubedata) && inTriangle(vecticalBorder, tempData_0, tempData_1, levelBorder, smallCubedata))
                    sum += cube[smallCubedata[2]][smallCubedata[1]][smallCubedata[0]];
        }
        levelBorder--;
        vecticalBorder--;

    }
    return sum;
}

void cutMatrix(int edgeLength, char cubePiece, int cubePieceIndex, int cube[32][32][32], long long int matrix[32][32])
{
    switch (cubePiece)
    {
    case 'v':
        for (int i = 0; i < edgeLength; i++)
            for (int j = 0; j < edgeLength; j++)
                matrix[j][i] = cube[i][cubePieceIndex][j];
        break;
    case 'l':
        for (int i = 0; i < edgeLength; i++)
            for (int j = 0; j < edgeLength; j++)
                matrix[j][i] = cube[i][j][cubePieceIndex];
        break;
    case 'p':
        for (int i = 0; i < edgeLength; i++)
            for (int j = 0; j < edgeLength; j++)
                matrix[i][j] = cube[cubePieceIndex][j][i];
        break;
    }
}

long long int determinants(long long int matrix[32][32], int edgeLength)
{
    long long int sign = 1;
    long long int sum = 0;

    for (int i = 0; i < edgeLength - 1; i++)
    {
        if (matrix[i][i] == 0)
        {
            for (int j = i + 1; j < edgeLength; j++)
            {
                if (matrix[j][i] != 0)
                {
                    swap(matrix[j], matrix[i]);
                    sign = -sign;
                    break;
                }
                if (j == edgeLength - 1)
                    return 0;
            }
        }

        for (int k = i + 1; k < edgeLength; k++)
        {
            for (int j = i + 1; j < edgeLength; j++)
            {
                matrix[k][j] = matrix[k][j] * matrix[i][i] - matrix[i][j] * matrix[k][i];

                if (i != 0)
                    matrix[k][j] = matrix[k][j] / matrix[i - 1][i - 1];
            }
        }
    }
    sum = sign * matrix[edgeLength - 1][edgeLength - 1];
    return sign * matrix[edgeLength - 1][edgeLength - 1];
}


int main()
{
    int cube[32][32][32];
    long long int matrix[32][32];
    unsigned short int edgeLength = 0;
    char operationCode = 0;
    int data[6];
    int smallCubedata[6];
    char cubePiece = 0;
    int  cubePieceIndex = 0;

    cin >> edgeLength;

    for (int i = 0; i < edgeLength; i++)
        for (int j = 0; j < edgeLength; j++)
            for (int k = 0; k < edgeLength; k++)
                cin >> cube[i][k][j];

    while (operationCode != 'E')
    {
        cin >> operationCode;

        switch (operationCode)
        {
        case 'C':
            for (int i = 0; i < 6; i++)
                cin >> data[i];

            NormalizeCuboid(data, edgeLength);
            cout << SumCuboid(edgeLength, cube, data) << endl;
            break;

        case  'T':
            for (int i = 0; i < 4; i++)
                cin >> data[i];
            for (int i = 0; i < 4; i++)
                smallCubedata[i] = data[i];
            NormalizeOctalTetrahedron(smallCubedata, edgeLength);
            cout << SumTetrahedron(edgeLength, cube, data, smallCubedata) << endl;
            break;

        case 'O':
            for (int i = 0; i < 4; i++)
                cin >> data[i];
            for (int i = 0; i < 4; i++)
                smallCubedata[i] = data[i];
            NormalizeOctalTetrahedron(smallCubedata, edgeLength);
            cout << SumOctal(edgeLength, cube, data, smallCubedata) << endl;
            break;

        case 'D':
            cin >> cubePiece >> cubePieceIndex;
            cutMatrix(edgeLength, cubePiece, cubePieceIndex, cube, matrix);
            cout << determinants(matrix, edgeLength) << endl;
            break;

        case 'E':
            break;
        }
    }
    return 0;
}