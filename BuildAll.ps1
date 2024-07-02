cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-001.c
if (!$?) { throw "Failed while building euler-001.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-002.c
if (!$?) { throw "Failed while building euler-002.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-003.c
if (!$?) { throw "Failed while building euler-003.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-004.c
if (!$?) { throw "Failed while building euler-004.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-005.c
if (!$?) { throw "Failed while building euler-005.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-006.c
if (!$?) { throw "Failed while building euler-006.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-007.c
if (!$?) { throw "Failed while building euler-007.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-008.c
if (!$?) { throw "Failed while building euler-008.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-009.c
if (!$?) { throw "Failed while building euler-009.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-010.c
if (!$?) { throw "Failed while building euler-010.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-011.c
if (!$?) { throw "Failed while building euler-011.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-012.c
if (!$?) { throw "Failed while building euler-012.c" }

# /wd6053: The prior call to 'strncpy' might not zero-terminate string 'trimmed_line'.
cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo /wd6053 .\src\euler-013.c
if (!$?) { throw "Failed while building euler-013.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-014.c
if (!$?) { throw "Failed while building euler-014.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-015.c
if (!$?) { throw "Failed while building euler-015.c" }

cl /W4 /Fe:bin/ /Fo:bin/ /analyze:autolog- /sdl /nologo .\src\euler-016.c
if (!$?) { throw "Failed while building euler-016.c" }
