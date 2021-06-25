#include <iostream>
#include "GFA.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Running GFA test\n";

    GFA::Vector3DB vecA(5,0,0);
    GFA::Vector3DB vecAN(1,0,0);
    GFA::Vector3DB vecB(10,10,0);
    GFA::Vector3DB vecBN(0.707107,0.707107,0);
    GFA::Vector3DB vecC(0,5,0);
    GFA::Vector3DB vecCN(0,1,0);
    GFA::Vector3DB vecD(10,0.1,0);

    GFA::NormalB normA(5,0,0);
    GFA::NormalB normB(10,10,0);
    GFA::Vector3DB vecResultA, vecResultB;
    GFA::NormalB normResultA, normResultB;
    GFA::Scalar scalarResultA, scalarResultB;
    GFA::Scalar multi = 2.0;

    std::cout << "normA: " << normA << std::endl;
    std::cout << "normB: " << normB << std::endl;

    normResultA = vecB;
    std::cout << "normResultA: " << normResultA << std::endl;
    normResultA = normB;
    std::cout << "normResultA: " << normResultA << std::endl;
    vecResultA = vecB;
    std::cout << "normResultA: " << vecResultA << std::endl;
    vecResultA = normB;
    std::cout << "normResultA: " << vecResultA << std::endl;

    std::cout << "vecA * vecB:\t"; vecA * vecB;
    std::cout << "vecA.normal() * vecB.normal():\t"; vecA.normal() * vecB.normal();
    std::cout << "normA * normB:\t"; normA * normB;
    std::cout << "normA * vecB:\t"; normA * vecB;
    std::cout << "vecB.normal() * normA:\t"; vecB.normal() * normA;

    std::cout << "vecB * multi:\t"; vecB * multi;
    std::cout << "normB * multi:\t"; normB * multi;

    normResultA = normB;
    std::cout << "normResultA *= multi:\t"; normResultA *= multi;
    std::cout << "normResultA:\t" << normResultA << std::endl;

    std::cout << "vecA ^ vecB:\t"; vecA ^ vecB;
    std::cout << "vecA.normal() ^ vecB.normal():\t"; vecA.normal() ^ vecB.normal();
    std::cout << "normA ^ normB:\t"; normA ^ normB;
    std::cout << "normA ^ vecB:\t"; normA ^ vecB;
    std::cout << "vecB.normal() ^ normA:\t"; vecB.normal() ^ normA;
    std::cout << "vecA ^ vecC:\t"; vecA ^ vecC;
    std::cout << "vecA.normal() ^ vecC.normal():\t"; vecA.normal() ^ vecC.normal();
    std::cout << "vecA ^ vecD:\t"; vecA ^ vecD;
    std::cout << "vecA.normal() ^ vecD.normal():\t"; vecA.normal() ^ vecD.normal();

    normResultA = vecA ^ vecD;
    std::cout << "normResultA = vecA ^ vecD\n";
    std::cout << "normResultA:\t" << normResultA << std::endl;

    std::cout << "vecA ^ vecA:\t"; vecA ^ vecA;
    normResultA = vecA ^ vecA;
    std::cout << "normResultA = vecA ^ vecA\n";
    std::cout << "normResultA:\t" << normResultA << std::endl;

    std::cout << "vecA ^ vecA:\t"; vecA ^ vecA;
    vecResultA = vecA ^ vecA;
    std::cout << "vecResultA = vecA ^ vecA\n";
    std::cout << "vecResultA:\t" << vecResultA << std::endl;

    std::cout << "vecA + vecB:\t"; vecA + vecB;
    std::cout << "vecA.normal() + vecB.normal():\t"; vecA.normal() + vecB.normal();
    std::cout << "normA + normB:\t"; normA + normB;
    std::cout << "normA + vecB:\t"; normA + vecB;
    std::cout << "vecB.normal() + normA:\t"; vecB.normal() + normA;
    std::cout << "vecA + vecC:\t"; vecA + vecC;
    std::cout << "vecA.normal() + vecC.normal():\t"; vecA.normal() + vecC.normal();
    std::cout << "vecA + vecD:\t"; vecA + vecD;
    std::cout << "vecA.normal() + vecD.normal():\t"; vecA.normal() + vecD.normal();
    
    std::cout << "vecA + vecB:\t";
    normResultA = vecA + vecB;
    std::cout << "normResultA = vecA + vecB\n";
    std::cout << "normResultA:\t" << normResultA << std::endl;

    std::cout << "vecA + vecB:\t";
    vecResultA = vecA + vecB;
    std::cout << "vecResultA = vecA + vecB\n";
    std::cout << "vecResultA:\t" << vecResultA << std::endl;

    std::cout << "vecB / multi:\t"; vecB / multi;
    std::cout << "normB / multi:\t"; normB / multi;

    normResultA = normB;
    std::cout << "normResultA /= multi:\t"; normResultA /= multi;
    std::cout << "normResultA:\t" << normResultA << std::endl;

    //std::cout << "End test\n";
    return 0;
}
