#This File Makefile Scrpit

#Comand Separator Tab Keyboard!!!

include Makefile.Header

.PHONY = all beta_version beta_version2 beta_version3 bebug_mode_version bebug_mode_version2 bebug_mode_version3 run.bat run_bebug.bat run run_bebug clean LINK_OBJECTIVE LINK_OBJECTIVES
all:

	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 01

	- @make debug_mode_version
	- @make debug_mode_version2
	- @make debug_mode_version3
  
	- @make beta_version
	- @make beta_version2
	- @make beta_version3

beta_version:

	- @cd /d ".\\"
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 02

	- $(CREATE_FOLDER) $(RELEASE_OBJECTIVES_VERSION_FOLDER)
	- $(CREATE_FOLDER) $(RELEASE_EXECUTE_VERSION_FOLDER)
	- $(MINGW_CPP) -Wall -O2 -c $(SOURCES_VERSION) -o $(RELEASE_OBJECTIVES_VERSION)
	- $(LINK_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION) -o $(RELEASE_EXECUTE_FILE_VERSION) 

beta_version2:

	- @cd /d ".\\"
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 03

	- $(CREATE_FOLDER) $(RELEASE_OBJECTIVES_VERSION2_FOLDER)
	- $(CREATE_FOLDER) $(RELEASE_EXECUTE_VERSION2_FOLDER)
	- $(MINGW_CPP) -Wall -O2 -c $(SOURCES_VERSION2) -o $(RELEASE_OBJECTIVES_VERSION2)
	- $(LINK_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION2) -o $(RELEASE_EXECUTE_FILE_VERSION2)

beta_version3:

	- @cd /d ".\\"
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 04

	- $(CREATE_FOLDER) $(RELEASE_OBJECTIVES_VERSION3_FOLDER)
	- $(CREATE_FOLDER) $(RELEASE_EXECUTE_VERSION3_FOLDER)
	- $(MINGW_CPP) -Wall -O2 -c $(SOURCES_VERSION3) -o $(RELEASE_OBJECTIVES_VERSION3)
	- $(LINK_OBJECTIVES) $(RELEASE_OBJECTIVES_VERSION3) -o $(RELEASE_EXECUTE_FILE_VERSION3)

debug_mode_version:

	- @cd /d ".\\"
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 05

	- $(CREATE_FOLDER) $(DEBUG_OBJECTIVES_VERSION_FOLDER)
	- $(CREATE_FOLDER) $(DEBUG_EXECUTE_VERSION_FOLDER)
	- $(MINGW_DEBUG_CPP) $(SOURCES_VERSION) -o $(DEBUG_OBJECTIVES_VERSION)
	- $(LINK_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION) -o $(DEBUG_EXECUTE_FILE_VERSION)

debug_mode_version2:

	- @cd /d ".\\"
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 06

	- $(CREATE_FOLDER) $(DEBUG_OBJECTIVES_VERSION2_FOLDER)
	- $(CREATE_FOLDER) $(DEBUG_EXECUTE_VERSION2_FOLDER)
	- $(MINGW_DEBUG_CPP) $(SOURCES_VERSION2) -o $(DEBUG_OBJECTIVES_VERSION2)
	- $(LINK_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION2) -o $(DEBUG_EXECUTE_FILE_VERSION2)

debug_mode_version3:

	- @cd /d ".\\"
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 07

	- $(CREATE_FOLDER) $(DEBUG_OBJECTIVES_VERSION3_FOLDER)
	- $(CREATE_FOLDER) $(DEBUG_EXECUTE_VERSION3_FOLDER)
	- $(MINGW_DEBUG_CPP) $(SOURCES_VERSION3) -o $(DEBUG_OBJECTIVES_VERSION3)
	- $(LINK_OBJECTIVES) $(DEBUG_OBJECTIVES_VERSION3) -o $(DEBUG_EXECUTE_FILE_VERSION3)

run.bat:

	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 08
	- @echo @echo off >> run.bat
	- @echo.>>run.bat
	- @echo cd /d $(RELEASE_EXECUTE_VERSION3_FOLDER) >> run.bat
	- @echo.>>run.bat
	- @echo start CUI_EncryptDecryptFile_BetaVersion3.exe >> run.bat
	- start ".\\run.bat"

run_debug.bat:

	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 09
	- cd /d ".\\"
	- @echo @echo off >> run_debug.bat
	- @echo.>>run_debug.bat
	- @echo cd /d $(DEBUG_EXECUTE_VERSION3_FOLDER) >> run.bat
	- @echo.>>run_debug.bat
	- @echo start CUI_EncryptDecryptFile_DebugVersion3.exe >> run_debug.bat
	- start ".\\run_debug.bat"

run:

	- make run.bat

run_debug:

	- make run_debug.bat

clean:

	- @cd /d ".\\"
	- $(HIDDEN_RUN_MODE)
	- $(COMMAND_WINDOW_COLOR) 10

	- $(DELETE) $(DEBUG_OBJECTIVES_VERSION)
	- $(DELETE) $(DEBUG_OBJECTIVES_VERSION2)
	- $(DELETE) $(DEBUG_OBJECTIVES_VERSION3)
 
	- $(DELETE) $(DEBUG_EXECUTE_FILE_VERSION)
	- $(DELETE) $(DEBUG_EXECUTE_FILE_VERSION2)
	- $(DELETE) $(DEBUG_EXECUTE_FILE_VERSION3)
 
	- $(DELETE) $(RELEASE_OBJECTIVES_VERSION)
	- $(DELETE) $(RELEASE_OBJECTIVES_VERSION2)
	- $(DELETE) $(RELEASE_OBJECTIVES_VERSION3)
 
	- $(DELETE) $(RELEASE_EXECUTE_FILE_VERSION)
	- $(DELETE) $(RELEASE_EXECUTE_FILE_VERSION2)
	- $(DELETE) $(RELEASE_EXECUTE_FILE_VERSION3)
 
	- $(DELETE) ".\\Binary\\Debug\\*.exe"
	- $(DELETE) ".\\Binary\\Release\\*.exe"
	- $(DELETE) ".\\Objectives\\Debug\\*.o"
	- $(DELETE) ".\\Objectives\\Release\\*.o"
	
	- $(DELETE) ".\\run.bat"
 
	- $(REMOVE_FOLDER) $(DEBUG_OBJECTIVES_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_OBJECTIVES_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_OBJECTIVES_VERSION3_FOLDER)

	- $(REMOVE_FOLDER) $(RELEASE_OBJECTIVES_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_OBJECTIVES_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_OBJECTIVES_VERSION3_FOLDER)

	- $(REMOVE_FOLDER) $(DEBUG_EXECUTE_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_EXECUTE_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(DEBUG_EXECUTE_VERSION3_FOLDER)

	- $(REMOVE_FOLDER) $(RELEASE_EXECUTE_VERSION_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_EXECUTE_VERSION2_FOLDER)
	- $(REMOVE_FOLDER) $(RELEASE_EXECUTE_VERSION3_FOLDER)
 
 	- $(REMOVE_FOLDER) ".\\Binary\\"
	- $(REMOVE_FOLDER) ".\\Objectives\\"
	
	- $(DELETE) ".\\run_debug.bat"
