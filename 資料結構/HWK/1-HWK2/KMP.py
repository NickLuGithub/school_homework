#coding = 'UTF-8'
import ctypes,sys
import os

STD_INPUT_HANDLE = -10
STD_OUTPUT_HANDLE = -11
STD_ERROR_HANDLE = -12

FOREGROUND_RED = 0x0c # red
FOREGROUND_GREEN = 0x0a # green.
FOREGROUND_BLUE = 0x09 # blue.
std_out_handle = ctypes.windll.kernel32.GetStdHandle(STD_OUTPUT_HANDLE)

def set_cmd_text_color(color, handle=std_out_handle):
    Bool = ctypes.windll.kernel32.SetConsoleTextAttribute(handle, color)
    return Bool

def resetColor():
    set_cmd_text_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

def printWhiteBlack(mess):
    set_cmd_text_color(0xf0)
    sys.stdout.write(mess)
    resetColor()

def fileopen():
    filename = input("請輸入資料檔名:");
    file = open(filename, 'r', encoding = 'UTF-8');
    word = file.read();
    file.close;
    #printword(word);
    return word;

def printword(word, pat):
    kmp = KMP()
    wordsearch = kmp.search(word, pat)
    n = len(pat)
    p = 0
    for i in range(0, len(word)):
        if(i >= wordsearch[p] and i < wordsearch[p] + n):
            while (i >= wordsearch[p] and i < wordsearch[p] + n):
                printWhiteBlack(word[i]);
                i += 1;
            i -= 1;
            p += 1;
        else:
            print(word[i], end = '')
class KMP:
    def partial(self, pattern):
        ret = [0]
        
        for i in range(1, len(pattern)):
            j = ret[i - 1]
            while j > 0 and pattern[j] != pattern[i]:
                j = ret[j - 1]
            ret.append(j + 1 if pattern[j] == pattern[i] else j)
        return ret
        
    def search(self, T, P):
        partial, ret, j = self.partial(P), [], 0
        
        for i in range(len(T)):
            while j > 0 and T[i] != P[j]:
                j = partial[j - 1]
            if T[i] == P[j]: j += 1
            if j == len(P): 
                ret.append(i - (j - 1))
                j = partial[j - 1]
            
        return ret


word = fileopen()
#printWhiteBlack(word)
pat = input("請輸入要收尋得字:")
kmp = KMP()
printword(word, pat)
os.system("pause")
