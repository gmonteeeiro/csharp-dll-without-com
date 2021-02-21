using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using RGiesecke.DllExport;

namespace csharp_dll_without_com
{
    public static class MethodsDLL
    {
        private static int number1;
        private static int number2;
        private static string text;

        [DllExport(CallingConvention = CallingConvention.Cdecl)]
        public static void AllocTwoNumbers(int n1, int n2)
        {
            number1 = n1;
            number2 = n2;
        }

        [DllExport(CallingConvention = CallingConvention.Cdecl)]
        public static void GetSum(out int result)
        {
            result = number1 + number2;
        }

        [DllExport(CallingConvention = CallingConvention.Cdecl)]
        public static void AllocText(string t)
        {
            text = t;
        }

        [DllExport(CallingConvention = CallingConvention.Cdecl)]
        public static void GetText(out string result)
        {
            result = text;
        }

        [DllExport(CallingConvention = CallingConvention.Cdecl)]
        public static void ShowError(string message)
        {
            MessageBox.Show(message, "error", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        [DllExport(CallingConvention = CallingConvention.Cdecl)]
        public static void GetString(out string result)
        {
            result = "Texto criado no C#";
        }
    }
}
