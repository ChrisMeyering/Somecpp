// Author: Chris Meyering
// Class: CS 110C
// Created: Monday November 10th 2014
// Semester: Fall 2014
// Instructor: Steve Abensohn
// Input: name of containing data to be sorted
// Output: Listing of: Unsorted data
//                     Sorted data
//                     Sorted index array
// Last Modified: Tuesday November 11th 2014
// Modified by: Chris Meyering

#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

static const void printIndexArray(const vector<size_t> idx);
static const void printSortedData(const vector<string> data,
             const vector<size_t> idx);
static const vector<size_t> indirectInsertionSort(
             const vector<string> data);
static const void printData(const vector<string> data);
static bool copyFileToVector (vector<string>& data);
static string getFilename(string& filename);


// call all necessary functions to sort a file containing data.
int main()
{
  vector<string> data;
  if (copyFileToVector(data)){
    printData(data);
    vector<size_t> idx = indirectInsertionSort(data);
    printSortedData(data, idx);
    printIndexArray(idx);
  }
}


// input name of file and return it to main
static string getFilename(string &filename)
{
  cout << "Enter name of file: ";
  cin >> filename;
  return filename;
}


// false if can't open file. Will copy contents of file to vector 
// if the file has been opened successfully.
static bool copyFileToVector (vector<string>& data)
{
  string filename;
  getFilename(filename);
  ifstream myfile;
  myfile.open(filename.c_str());
  if (myfile.fail())
  {
    cout << "Cannot open file.\n";
    return false;
  }
  string line;
  while (!myfile.eof())
  {
    getline (myfile, line);
    if (line != "")
      data.push_back(line);
  }
  myfile.close();
  return true;
}


// print data contained in vector.
static const void printData(const vector<string> data)
{
    cout << "\nUnsorted data:\n";
    ostream_iterator<string> out_it (cout, "\n");
    copy(data.begin(), data.end(), out_it);
}


// create and index array of same size as the parameter
// read through vector to be sorted and sort corresponding
// elements in the index array
// return sorted index array to main
static const vector<size_t> indirectInsertionSort(
             const vector<string> data)
{
  vector<size_t> idx(data.size());
  for (size_t i = 0; i < data.size(); i++)
  {
    idx[i] = i;
  }
  for (size_t i = 1; i < data.size(); i++)
  {
    size_t valueToSort = idx[i];
    size_t j;
    for (j = i; j > 0 && data[valueToSort] <= data[idx[j - 1]]; j--)
    {
      idx[j] = idx[j - 1];
    }
    idx[j] = valueToSort;
  }
  return idx;
}


// prints the sorted data by printing data[sortedIndex[i]] for i[0,size]
static const void printSortedData(const vector<string> data,
             const vector<size_t> idx)
{
  cout << "\nSorted data:\n";
  for (size_t i = 0; i < data.size(); i++)
  {
    cout << data[idx[i]] << endl;
  }
}


// prints index array
static const void printIndexArray(const vector<size_t> idx)
{
  cout << "\nIndex array:\n";
  for (size_t i = 0; i < idx.size(); i++)
  {
     cout << idx[i] << endl;
  }
}
