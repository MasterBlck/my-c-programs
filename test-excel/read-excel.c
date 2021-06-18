#include <stdio.h>
#include <xlsxio_read.h>

int main(int argc, char* argv[]){
	//open .xlsx file for reading
	char* filename = "Ejemplo.xlsx";
	xlsxioreader xlsxioread;

	if ((xlsxioread = xlsxioread_open(filename)) == NULL) {
  		printf("Error opening .xlsx file\n");
 		return 1;
	}

	char* value;
	xlsxioreadersheet sheet;
	const char* sheetname = "Sheet1";  //ponle nombre a la hoja
	printf("Contents of first sheet:\n");

	if ((sheet = xlsxioread_sheet_open(xlsxioread, sheetname, XLSXIOREAD_SKIP_EMPTY_ROWS)) != NULL) {
		//lee todos los rows
		while (xlsxioread_sheet_next_row(sheet)) {
			//lee todas las columnas
			while ((value = xlsxioread_sheet_next_cell(sheet)) != NULL) {
				printf("%s\t", value);
				xlsxioread_free(value);
			}
			printf("\n");
		}
		xlsxioread_sheet_close(sheet);
	}

	//clean up
	xlsxioread_close(xlsxioread);

	return 0;
}
