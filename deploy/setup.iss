#define MyAppName "FactDev"
#define MyAppVersion "1.0"
#define MyAppPublisher "Fact Team"
#define MyAppURL "http://www.fact-team.github.io/"
#define MyAppExeName "FactDev.exe"

[Setup]
AppId={{9723FA42-755A-4C59-AF8D-7C0DCE971A0F}}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\FactDev
DefaultGroupName={#MyAppName}
OutputDir=C:\Users\Aroquemaurel\Documents\FactDev
OutputBaseFilename=setup_FactDev
SetupIconFile=C:\Users\Aroquemaurel\Documents\FactDev\images\FACTDev.ico
Compression=lzma
SolidCompression=yes

[Languages]
Name: "french"; MessagesFile: "compiler:Languages\French.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "C:\Users\Aroquemaurel\Documents\build-FactDev-Desktop_Qt_5_4_1_MinGW_32bit-Release\app\release\FactDev.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Aroquemaurel\Documents\build-FactDev-Desktop_Qt_5_4_1_MinGW_32bit-Release\app\release\*.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Aroquemaurel\Documents\build-FactDev-Desktop_Qt_5_4_1_MinGW_32bit-Release\app\release\sql\*"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\Aroquemaurel\Documents\build-FactDev-Desktop_Qt_5_4_1_MinGW_32bit-Release\app\release\platforms\*"; DestDir: "{app}\platforms"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Users\Aroquemaurel\Documents\build-FactDev-Desktop_Qt_5_4_1_MinGW_32bit-Release\app\release\sqldrivers\*"; DestDir: "{app}\sqldrivers"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Users\Aroquemaurel\Documents\build-FactDev-Desktop_Qt_5_4_1_MinGW_32bit-Release\app\release\manuel.pdf"; DestDir: "{app}\"; Flags: ignoreversion recursesubdirs createallsubdirs

; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:ProgramOnTheWeb,{#MyAppName}}"; Filename: "{#MyAppURL}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: filesandordirs; Name: "{userappdata}\{#MyAppName}"
