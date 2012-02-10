using System;
using System.Collections.Generic;
using System.Text;

namespace ListFiles
{
    class Program
    {
        static void DisplayFileInfo(System.IO.FileInfo file)
        {
            Console.WriteLine("FileName: {0}, Size: {1}", file.Name, file.Length);
        }

        static long ListFiles(System.IO.DirectoryInfo directory, string pattern)
        {
            long totalLenth = 0;
            foreach (System.IO.FileInfo file in directory.GetFiles(pattern))
            {
                DisplayFileInfo(file);
                totalLenth += file.Length;
            }

            return totalLenth;
        }

        static long ListFiles(System.IO.DirectoryInfo directory)
        {
            long totalLength = 0;
            totalLength += ListFiles(directory, "*.h");
            totalLength += ListFiles(directory, "*.c");
            totalLength += ListFiles(directory, "*.py");
            totalLength += ListFiles(directory, "*.cpp");

            return totalLength;
        }

        static void ListAll(System.IO.DirectoryInfo directory)
        {
            ListFiles(directory);
            foreach (System.IO.DirectoryInfo subdir in directory.GetDirectories())
            {
                //Console.WriteLine("PathName:{0}", subdir.Name);
                ListAll(subdir);
            }
        }

        static void ListAll(string pathName)
        {
            System.IO.DirectoryInfo directory = new System.IO.DirectoryInfo(pathName);
            ListAll(directory);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("This program lists all the files in the directory: ");

            string pathName = @"E:\dev\cucb";
            ListAll(pathName);

            Console.WriteLine("Press any key to quit.");
            Console.ReadLine();
        }
    }
}
