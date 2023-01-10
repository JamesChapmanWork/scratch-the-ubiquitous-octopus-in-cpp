Debugging crash dumps in Windows
================================

### Setup

Get Debugging Tools for Windows (WinDbg) from the [Windows SDK](https://developer.microsoft.com/en-gb/windows/downloads/windows-sdk/)

When running the installer, select and install `Debugging Tools for Windows`.

Set the below environment variables and point them to the relevant source code folders and symbols servers.
```
_NT_SOURCE_PATH=D:\Source\Folder_1;D:\Source\Folder_2;C:\Users\Username\github\project;
_NT_SYMBOL_PATH=CACHE*C:\SymbolCache;C:\Symbols;SRV*https://internal-server/symbols;SRV*https://internal-server2/symbols;SRV*https://msdl.microsoft.com/download/symbols;
```



### Analyzing crash dumps

Open `windbg` and load the dump. The source code needs to match what was built, this might mean checking out the revision that the crashed build was built from.

run `!analyze -v` to see where the crash occured.

