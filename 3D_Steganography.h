// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 MY3DSTEGANOGRAPHY_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// MY3DSTEGANOGRAPHY_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef MY3DSTEGANOGRAPHY_EXPORTS
#define MY3DSTEGANOGRAPHY_API __declspec(dllimport)
#else
#define MY3DSTEGANOGRAPHY_API __declspec(dllexport)
#endif



// 此类是从 dll 导出的
class MY3DSTEGANOGRAPHY_API CMy3DSteganography {
public:
	CMy3DSteganography(void);
	// TODO: 在此处添加方法。
};

extern MY3DSTEGANOGRAPHY_API int nMy3DSteganography;

MY3DSTEGANOGRAPHY_API int fnMy3DSteganography(void);

extern "C"  MY3DSTEGANOGRAPHY_API void image_encode(char* filename, char* file0, char* file1, char* file2, char* file3);