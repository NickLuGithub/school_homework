
CREATE TABLE Patient(
	Idcard	CHAR(10)	NOT NULL,
	Name	CHAR(10)	NOT NULL,
	Address	CHAR(20)	NOT NULL,
	Birthday DATE		NOT NULL,
	Blood	CHAR(10)	NOT NULL,
	Allergy CHAR(50)			,
	Phone   CHAR(12)    NOT NULL,
	PRIMARY KEY (Idcard)	
);

CREATE TABLE Image (
	Imageid		INT			NOT NULL,
	Idcard		CHAR(10)	NOT NULL,
	Radiologyid CHAR(20)	REFERENCES Radiology( Radiologyid)
	PRIMARY KEY (Imageid),
);

CREATE TABLE Radiology (
	Radiologyid	CHAR(20)	NOT NULL,
	PRIMARY KEY (Radiologyid)
);

CREATE TABLE Requistion (
	Requistionid	INT			NOT NULL,
	Idcard			CHAR(10)    NOT NULL,
	Medicalid		INT			NOT NULL REFERENCES Medicalrecord (Medicalid),
	PRIMARY KEY (Requistionid),
);

CREATE TABLE Medicalrecord (
	Medicalid	INT				NOT NULL,
	PRIMARY KEY (Medicalid)
);

