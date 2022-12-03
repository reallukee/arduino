//
//  ASM(Arduino Serial Manager)
//
//  Questo progetto è distribuito sotto licenza MIT.
//  Questo progetto è disponibile su GitHub.
//
//  Repository:     https://github.com/reallukee/arduino/
//  Descrizione:    MAIN
//  Autore:         Luca Pollicino (https://github.com/reallukee/)
//  Versione:       1.0.0
//

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;

namespace ASM
{
    internal class Program
    {
        static Thread ReadThread;
        static SerialPort Arduino;


        const string WORK = "\x1b[0;90m[\x1b[93m....\x1b[90m]\x1b[37;3m";
        const string INFO = "\x1b[0;90m[\x1b[92mINFO\x1b[90m]\x1b[37;3m";
        const string FAIL = "\x1b[0;90m[\x1b[91mFAIL\x1b[90m]\x1b[37;3m";


        public static void Main(string[] Args)
        {
            Console.Title = "ASM";
            Console.ForegroundColor = ConsoleColor.White;
            Console.BackgroundColor = ConsoleColor.Black;
            Console.InputEncoding = Encoding.Unicode;
            Console.OutputEncoding = Encoding.Unicode;

            Title();

            foreach (string S in SerialPort.GetPortNames())
            {
                Console.WriteLine($"     \x1b[0m* \x1b[96m{S} {SerialPort.GetPortNames}");
            }

            Console.WriteLine("\n    \x1b[0mPort Name");
            Console.Write("    >>> \x1b[94m");
            string PortName = Console.ReadLine();

            Console.WriteLine("\n    \x1b[0mBaud Rate");
            Console.Write("    >>> \x1b[94m");
            int BaudRate = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("\x1b[0m");

            Arduino = new(PortName, BaudRate);
            ReadThread = new(Read);

            Console.WriteLine($"\x1b[0m<<< {WORK} Connessione a \x1b[96m{Arduino.PortName}\x1b[0m...");

            try
            {
                Arduino.Open();
                Console.WriteLine($"\x1b[0m<<< {INFO} Connessione Riuscita!");
            }
            catch
            {
                Console.WriteLine($"\x1b[0m<<< {FAIL} Connessione Fallita!");
                Console.ReadKey();
                return;
            }

            ReadThread.Start();

            bool DoLoop = true;

            while (DoLoop)
            {
                if (!Write())
                {
                    DoLoop = false;
                }
            }

            Console.WriteLine($"\x1b[0m<<< {WORK} Disconnessione da \x1b[96m{Arduino.PortName}\x1b[0m...");

            try
            {
                Arduino.Close();
                Console.WriteLine($"\x1b[0m<<< {INFO} Disconnessione Riuscita!");
            }
            catch
            {
                Console.WriteLine($"\x1b[0m<<< {FAIL} Disconnessione Fallita!");
                Console.ReadKey();
                return;
            }
        }


        public static void Title()
        {
            Console.WriteLine("\x1b[0m                                             ");
            Console.WriteLine("    \x1b[91m _____ \x1b[37m       _     _           ");
            Console.WriteLine("    \x1b[91m|  _  |\x1b[37m ___ _| |_ _|_|___ ___   ");
            Console.WriteLine("    \x1b[91m|     |\x1b[37m|  _| . | | | |   | . |  ");
            Console.WriteLine("    \x1b[91m|__|__|\x1b[37m|_| |___|___|_|_|_|___|  ");
            Console.WriteLine("    \x1b[93m _____ \x1b[37m         _     _         ");
            Console.WriteLine("    \x1b[93m|   __|\x1b[37m ___ ___|_|___| |        ");
            Console.WriteLine("    \x1b[93m|__   |\x1b[37m| -_|  _| | .'| |        ");
            Console.WriteLine("    \x1b[93m|_____|\x1b[37m|___|_| |_|__,|_|        ");
            Console.WriteLine("    \x1b[94m _____ \x1b[37m                         ");
            Console.WriteLine("    \x1b[94m|     |\x1b[37m ___ ___ ___ ___ ___ ___ ");
            Console.WriteLine("    \x1b[94m| | | |\x1b[37m| .'|   | .'| . | -_|  _|");
            Console.WriteLine("    \x1b[94m|_|_|_|\x1b[37m|__,|_|_|__,|_  |___|_|  ");
            Console.WriteLine("    \x1b[94m       \x1b[37m    |___|                ");
            Console.WriteLine("\x1b[0m                                             ");
            Console.WriteLine("    \x1b[36mv1.0.0 \x1b[90mby \x1b[36mLuca Pollicino");
            Console.WriteLine("\x1b[0m                                             ");
        }


        public static bool Write()
        {
            Console.Write("\x1b[0m>>> \x1b[96m");

            string Data = Console.ReadLine();

            if (Data.ToUpper() == "!QUIT")
            {
                return false;
            }
            else
            {
                try
                {
                    Arduino.Write(Encoding.UTF8.GetBytes(Data), 0, Data.Length);
                }
                catch (Exception Ex)
                {
                    Console.WriteLine($"{FAIL} {Ex.Message}");
                }
            }

            return true;
        }


        public static void Read()
        {
            while (Arduino.IsOpen)
            {
                if (Arduino.BytesToRead > 0)
                {
                    string Data = Arduino.ReadLine();

                    try
                    {
                        Console.WriteLine($"{INFO} {Data}");
                    }
                    catch (Exception Ex)
                    {
                        Console.WriteLine($"{FAIL} {Ex.Message}");
                    }

                    Console.Write("\x1b[0m>>> \x1b[96m");
                }
            }
        }
    }
}
