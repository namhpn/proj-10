use qlsv;

drop table diemsv;

CREATE TABLE diemsv (
  MASV char(3),
  MAMH char(3),
  DIEM float,
  Check(DIEM >= 0 AND DIEM <= 10),
  PRIMARY KEY (MASV,MAMH)
);

INSERT INTO diemsv
VALUES ('S01','M01',8.2),('S01','M03',5.6),('S01','M04',3.6),('S02','M02',2.2),('S02','M04',5),('S03','M05',5.2),('S04','M02',3.4),('S05','M01',7.4),('S06','M01',8.8),('S06','M04',8.6),('S07','M02',9),('S07','M03',9.2),('S08','M01',1),('S08','M02',0.8),('S08','M04',10),('S09','M01',3.2),('S09','M04',8),('S10','M05',8);

INSERT INTO diemsv
VALUES ('S99','M99',15);

UPDATE diemsv
SET DIEM = DIEM + 11
WHERE MASV = 'S01'
	AND MAMH = 'M01';

CREATE TABLE lop (
  MALP char(3) ,
  TENLP varchar(30) ,
  NK varchar(10) ,
  PRIMARY KEY (MALP)
);

INSERT INTO lop
VALUES ('L01','CN23','2022-2023'),('L02','CX23','2022-2023'),('L03','KT23','2022-2023');

CREATE TABLE monhoc (
  MAMH char(3) primary key ,
  TENMH varchar(30) NOT NULL ,
  SOTC int NOT NULL
);

INSERT INTO monhoc 
VALUES ('M01','Toan CD 1',3),('M02','Toan CD 2',3),('M03','Toan CD 3',3),('M04','Ly DC',3),('M05','Hoa',3);

insert into monhoc
values ('M99');

drop table sinhvien;

CREATE TABLE sinhvien (
  MASV char(3) ,
  TENSV varchar(40) ,
  DCSV varchar(100) ,
  MALP char(3) ,
  PRIMARY KEY (MASV),
  CONSTRAINT FK_LOP Foreign Key (MALP) References lop(MALP)
  ON DELETE SET NULL
  ON UPDATE CASCADE
);

INSERT INTO sinhvien
values ('S99','-','-','L07');

DELETE from lop
where MALP = 'L01';


INSERT INTO sinhvien
VALUES ('S01','Tuan','HCM','L01'),('S02','Tu','HN','L01'),('S03','Tuan','DN','L02'),('S04','Toan','HCM','L02'),('S05','Tung','HCM','L02'),('S06','Thuc','HCM','L03'),('S07','Hao','DN','L03'),('S08','Hung','HN','L02'),('S09','Hung','HCM','L03'),('S10','Huan','HCM','L02'),('S11','Trinh','HN','L02'),('S12','Trinh','HN','L01'),('S13','Trinh','DN','L01'),('S14','Chinh','DN','L03'),('S15','Xoai','LC','L01'),('S16','Oi','ST','L02'),('S17','Coc','ST','L02'),('S18','Man','LC','L01'),('S19','Tao','HCM','L02'),('S20','Dua','HCM','L01');
