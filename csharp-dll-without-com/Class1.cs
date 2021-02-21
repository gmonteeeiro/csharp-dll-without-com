using System;
using System.Runtime.InteropServices;
using net.r_eg.Conari.Types;
using RGiesecke.DllExport;

namespace csharp_dll_without_com
{
    public static class Class1
    {
        private static UnmanagedString msg;

        [DllExport(CallingConvention = CallingConvention.Cdecl)]
        public static void alloc()
        {
            msg = new UnmanagedString("teste feito pelo gabs");
        }

        [DllExport(CallingConvention = CallingConvention.Cdecl)]
        public static void free()
        {
            msg?.Dispose();
        }

        [DllExport(CallingConvention = CallingConvention.Cdecl)]
        public static IntPtr getMsg()
        {
            return msg;
        }
    }
}
