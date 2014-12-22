CREATE TABLE Client
(idClient NUMBER,
NomReferent VARCHAR2(30),
PrenomReferent VARCHAR2(30),
Societe VARCHAR2(30),
Adresse VARCHAR2(50),
CodePostal NUMBER,
Ville VARCHAR2(30),
Mail VARCHAR2(30),
TelephonePort NUMBER,
TelephoneFixe NUMBER,
Fax NUMBER,
CONSTRAINT pk_client PRIMARY KEY (idClient));

CREATE TABLE Project
(idProject NUMBER
Nom VARCHAR2(30),
Description TEXT,
TarifJournalier NUMBER,
idClient NUMBER,
CONSTRAINT pk_project PRIMARY KEY (idProject),
CONSTRAINT fk_project FOREIGN KEY (idClient)
REFERENCES Client (idClient));

CREATE TABLE Facturation
(idFacturation NUMBER,
Titre VARCHAR(20),
numero NUMBER,
Type BOOLEAN,
Date DATE,
CONSTRAINT pk_facturation PRIMARY KEY (idFacturation));

CREATE TABLE Prestation
(idPrestation NUMBER,
Description TEXT,
nbDays NUMBER,
CONSTRAINT pk_prestation PRIMARY KEY (idPrestation));

CREATE TABLE FacturationProject
(idProject NUMBER,
idFacturation NUMBER,
idPrestation NUMBER,
CONSTRAINT fk_factProjectP FOREIGN KEY (idProject)
REFERENCES Project (idProject),
CONSTRAINT fk_factProjectF FOREIGN KEY (idFacturation)
REFERENCES Facturation (idFacturation),
CONSTRAINT fk_factProjectPr FOREIGN KEY (idPrestation)
REFERENCES Prestation (idPrestation));

CREATE TABLE Users
(idUser NUMBER,
Nom VARCHAR2(30),
Prenom VARCHAR2(30),
Organisation VARCHAR2(30),
Titre VARCHAR2(20),
Adresse VARCHAR2(50),
CodePostal NUMBER,
Ville VARCHAR2(30),
Mail VARCHAR2(30),
TelephonePort NUMBER,
TelephoneFixe NUMBER,
NoSiret NUMBER,
CONSTRAINT pk_user PRIMARY KEY (idUser));
