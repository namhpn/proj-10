create database DLVN;
use DLVN;

create table MIEN
(	MAMN char(3) primary key,
	TENMN varchar(30));
    
insert into MIEN
values ('M01', 'Miền Nam'),
	('M02', 'Miền Bắc'),
	('M03', 'Miền Trung');
    

create table TITH
(	MATT char(3) primary key,
	TENTT varchar(30),
    DS float,
    DT float,
    MAMN char(3),
constraint FKTITH foreign key
(MAMN) references MIEN(MAMN) on update cascade );

insert into TITH
values ('T01','An Giang',2250.6,3536.8,'M01'),
('T02','Bà rịa Vũng Tàu',961.2,1987.4,'M01'),
('T03','Bạc Liêu',829.3,2585.3,'M01'),
('T04','Bắc Giang',1628.4,3827.4,'M02'),
('T05','Bắc Kạn',308.9,4859.4,'M02'),
('T06','Bắc Ninh',1022.5,822.7,'M02'),
('T07','Bến Tre',1360.3,2360.2,'M01'),
('T08','Bình Dương',1072,2695.2,'M01'),
('T09','Bình Định',1592.6,6039.6,'M03'),
('T10','Bình Phước',835.3,6874.6,'M01'),
('T11','Bình Thuận',1188.5,7810.4,'M03'),
('T12','Cà Mau',1251.2,5331.6,'M01'),
('T13','Cao Bằng',528.1,6724.6,'M02'),
('T14','Cần Thơ',1171.1,1401.6,'M01'),
('T15','Đà Nẵng',818.3,1283.4,'M03'),
('T16','Đắk Lắk',1777,13125.4,'M03'),
('T17','Đắk Nông',431,6515.3,'M03'),
('T18','Điện Biên',475.6,9562.9,'M02'),
('T19','Đồng Nai',2290.2,5903.4,'M01'),
('T20','Đồng Tháp',1682.7,3375.4,'M01'),
('T21','Gia Lai',1188.5,15536.9,'M03'),
('T22','Hà Giang',705.1,7945.8,'M02'),
('T23','Hà Nam',834.1,859.6,'M02'),
('T24','Hà Nội',6116.2,3348.5,'M02'),
('T25','Hà Tĩnh',1307.3,6025.6,'M03'),
('T26','Hải Dương',1745.3,1654.2,'M02'),
('T27','Hải Phòng',18459,1522.1,'M02'),
('T28','Hậu Giang',808.5,1601.1,'M01'),
('T29','Hòa Bình',817.7,4595.3,'M02'),
('T30','Hưng Yên',1167.1,923.4,'M02'),
('T31','Khánh Hòa',1162.1,5217.6,'M03'),
('T32','Kiên Giang',1727.6,6346.3,'M01'),
('T33','Kon Tum',401.5,9690.5,'M03'),
('T34','Lai Châu',335.3,9112.3,'M02'),
('T35','Lạng Sơn',759,8327.6,'M02'),
('T36','Lào Cai',602.3,6383.9,'M02'),
('T37','Lâm Đồng',1206.2,9772.2,'M03'),
('T38','Long An',1438.8,4493.8,'M01'),
('T39','Nam Định',1990.4,1652.3,'M02'),
('T40','Nghệ An',3131,16499,'M03'),
('T41','Ninh Bình',936.3,1388.7,'M02'),
('T42','Ninh Thuận',583.4,3358,'M03'),
('T43','Phú Thọ',1364.7,3528.1,'M02'),
('T44','Phú Yên',885.5,5060.6,'M03'),
('T45','Quảng Bình',857.8,8065.3,'M03'),
('T46','Quảng Nam',1492.1,10438.4,'M03'),
('T47','Quảng Ngãi',1302.6,5152.7,'M03'),
('T48','Quảng Ninh',1109.6,6099,'M02'),
('T49','Quảng Trị',635.7,4744.3,'M03'),
('T50','Sóc Trăng',1301.7,3311.8,'M01'),
('T51','Sơn La',1036.5,14174.4,'M02'),
('T52','Tây Ninh',1058.5,4049.3,'M01'),
('T53','Thái Bình',1827.9,1559.2,'M02'),
('T54','Thái Nguyên',1149.1,3534.4,'M02'),
('T55','Thanh Hóa',3712.5,11134.7,'M03'),
('T57','Thừa Thiên Huế',1150.8,5065.3,'M03'),
('T58','Tiền Giang',1742.1,2484.2,'M01'),
('T56','TP Hồ Chí Minh',6611.6,2095.6,'M01'),
('T59','Trà Vinh',1062,2295.1,'M01'),
('T60','Tuyên Quang',746.9,5870.4,'M02'),
('T61','Vĩnh Long',1069.1,1479.1,'M01'),
('T62','Vĩnh Phúc',1014.5,1231.8,'M02'),
('T63','Yên Bái',750.2,6899.5,'M02');

create table BG
(	MATT char(3),
	MAQG char(3),
    primary key (MATT,MAQG),
    constraint FKTT1 foreign key (MATT) references TITH(MATT)
    on update cascade);

insert into BG
values ('T33','CBC'),
('T21','CBC'),
('T16','CBC'),
('T17','CBC'),
('T10','CBC'),
('T52','CBC'),
('T38','CBC'),
('T20','CBC'),
('T01','CBC'),
('T32','CBC'),
('T18','LAO'),
('T51','LAO'),
('T55','LAO'),
('T40','LAO'),
('T25','LAO'),
('T45','LAO'),
('T49','LAO'),
('T57','LAO'),
('T46','LAO'),
('T33','LAO'),
('T48','CHI'),
('T35','CHI'),
('T14','CHI'),
('T22','CHI'),
('T36','CHI'),
('T34','CHI'),
('T18','CHI');

create table LG
(	MATT char(3),
	MALG char(3),
    primary key (MATT,MALG),
    constraint FKTT2 foreign key (MATT) references TITH(MATT)
    on update cascade,
    constraint FKLG foreign key (MATT) references TITH(MATT)
    on update cascade);
        
insert into LG
values ('T34','T18'),
('T34','T51'),
('T34','T36'),
('T34','T63'),
('T36','T22'),
('T36','T63'),
('T36','T34'),
('T22','T14'),
('T22','T60'),
('T22','T36'),
('T22','T63'),
('T14','T22'),
('T14','T60'),
('T14','T05'),
('T14','T35'),
('T18','T34'),
('T18','T51'),
('T63','T34'),
('T63','T51'),
('T63','T36'),
('T63','T22'),
('T63','T60'),
('T63','T43'),
('T60','T63'),
('T60','T22'),
('T60','T14'),
('T60','T05'),
('T60','T54'),
('T60','T62'),
('T60','T43'),
('T05','T60'),
('T05','T14'),
('T05','T35'),
('T05','T54'),
('T35','T14'),
('T35','T05'),
('T35','T54'),
('T35','T04'),
('T35','T48'),
('T51','T18'),
('T51','T34'),
('T51','T63'),
('T51','T43'),
('T51','T28'),
('T51','T54'),
('T43','T51'),
('T43','T63'),
('T43','T60'),
('T43','T62'),
('T43','T24'),
('T43','T28'),
('T62','T43'),
('T62','T60'),
('T62','T54'),
('T62','T24'),
('T54','T62'),
('T54','T60'),
('T54','T05'),
('T54','T35'),
('T54','T04'),
('T54','T24'),
('T04','T35'),
('T04','T54'),
('T04','T62'),
('T04','T24'),
('T04','T06'),
('T04','T26'),
('T04','T48'),
('T48','T35'),
('T48','T04'),
('T48','T26'),
('T48','T27'),
('T27','T48'),
('T27','T26'),
('T27','T53'),
('T26','T48'),
('T26','T04'),
('T26','T06'),
('T26','T30'),
('T26','T53'),
('T26','T27'),
('T06','T04'),
('T06','T26'),
('T06','T30'),
('T06','T24'),
('T24','T06'),
('T24','T04'),
('T24','T54'),
('T24','T62'),
('T24','T43'),
('T24','T28'),
('T24','T23'),
('T24','T30'),
('T28','T51'),
('T28','T43'),
('T28','T24'),
('T28','T23'),
('T28','T41'),
('T28','T54'),
('T53','T27'),
('T53','T26'),
('T53','T30'),
('T53','T23'),
('T53','T39'),
('T39','T53'),
('T39','T23'),
('T39','T41'),
('T23','T39'),
('T23','T53'),
('T23','T30'),
('T23','T24'),
('T23','T28'),
('T23','T41'),
('T30','T26'),
('T30','T06'),
('T30','T24'),
('T30','T23'),
('T30','T53'),
('T41','T39'),
('T41','T23'),
('T41','T28'),
('T41','T54'),
('T54','T28'),
('T54','T41'),
('T54','T40'),
('T40','T54'),
('T40','T25'),
('T25','T40'),
('T25','T45'),
('T45','T25'),
('T45','T49'),
('T49','T45'),
('T49','T57'),
('T57','T15'),
('T57','T49'),
('T57','T46'),
('T15','T57'),
('T15','T46'),
('T46','T57'),
('T46','T15'),
('T46','T33'),
('T46','T47'),
('T33','T46'),
('T33','T47'),
('T33','T21'),
('T47','T46'),
('T47','T33'),
('T47','T07'),
('T21','T33'),
('T21','T47'),
('T21','T07'),
('T21','T44'),
('T21','T16'),
('T07','T47'),
('T07','T21'),
('T07','T44'),
('T44','T07'),
('T44','T21'),
('T44','T16'),
('T44','T30'),
('T16','T21'),
('T16','T44'),
('T16','T30'),
('T16','T34'),
('T16','T17'),
('T30','T44'),
('T30','T16'),
('T30','T34'),
('T30','T42'),
('T42','T30'),
('T42','T34'),
('T42','T11'),
('T34','T17'),
('T34','T16'),
('T34','T30'),
('T34','T42'),
('T34','T11'),
('T34','T19'),
('T34','T10'),
('T17','T16'),
('T17','T34'),
('T17','T10'),
('T10','T17'),
('T10','T34'),
('T10','T19'),
('T10','T08'),
('T10','T52'),
('T19','T10'),
('T19','T34'),
('T19','T11'),
('T19','T02'),
('T19','T56'),
('T19','T08'),
('T11','T42'),
('T11','T34'),
('T11','T19'),
('T11','T02'),
('T02','T11'),
('T02','T19'),
('T02','T56'),
('T08','T10'),
('T08','T19'),
('T08','T56'),
('T08','T52'),
('T52','T10'),
('T52','T08'),
('T52','T56'),
('T52','T38'),
('T56','T52'),
('T56','T08'),
('T56','T19'),
('T56','T02'),
('T56','T38'),
('T38','T52'),
('T38','T56'),
('T38','T58'),
('T38','T20'),
('T58','T38'),
('T58','T20'),
('T58','T07'),
('T58','T61'),
('T20','T38'),
('T20','T58'),
('T20','T01'),
('T20','T14'),
('T20','T61'),
('T07','T58'),
('T07','T61'),
('T07','T59'),
('T01','T20'),
('T01','T14'),
('T01','T32'),
('T14','T01'),
('T14','T20'),
('T14','T61'),
('T14','T28'),
('T14','T32'),
('T61','T59'),
('T61','T07'),
('T61','T58'),
('T61','T20'),
('T61','T50'),
('T61','T28'),
('T59','T07'),
('T59','T61'),
('T59','T50'),
('T28','T14'),
('T28','T61'),
('T28','T50'),
('T28','T05'),
('T28','T32'),
('T50','T59'),
('T50','T28'),
('T50','T05'),
('T50','T32'),
('T32','T01'),
('T32','T14'),
('T32','T28'),
('T32','T05'),
('T32','T12'),
('T05','T50'),
('T05','T28'),
('T05','T32'),
('T05','T12'),
('T12','T32'),
('T12','T05');

--  5.1. Các tỉnh thành có diện tích > 15000 km2.
select *
from TITH
where DT > 15000;

-- 5.2. Các tỉnh thành của miền Bắc.
select B.*,A.TENMN
from MIEN A, TITH B
where TENMN = 'Miền Bắc'
	and A.MAMN = B.MAMN;
    
-- 5.3. Các quốc gia có biên giới với các tỉnh miền Trung.
select distinct C.MAQG as 'Quốc Gia'
from MIEN A, TITH B, BG C
where TENMN = 'Miền Trung'
	and A.MAMN = B.MAMN
    and B.MATT = C.MATT;
    
-- 5.4. Mật độ dân cư của các tỉnh miền Trung.
select TENMN,(sum(DS)*1000)/sum(DT) as 'Người/km2'
from MIEN A, TITH B
where TENMN = 'Miền Trung'
	and A.MAMN = B.MAMN
group by TENMN;

-- 5.5. Diện tích trung bình của các tỉnh miền Bắc.
select TENMN,AVG(DT) as 'Diện tích (km2)'
from MIEN A, TITH B
where TENMN = 'Miền Bắc'
	and A.MAMN = B.MAMN
group by TENMN;

-- 
create table R
(	A int,
	B int);
    
delimiter $$
create trigger insert_R before insert on R
for each row
begin
if new.A < new.B then
signal sqlstate '45000'
set message_text = 'Error: A < B';
end if;
end;
$$

insert into R
values (6,5);

delimiter $$
create trigger update_R before update on R
for each row
begin
if new.A < new.B then
signal sqlstate '45000'
set message_text = 'Error: A < B';
end if;
end;
$$

update R
set B = 2
where A = 6;

delimiter $$
create trigger delete_R before delete on R
for each row
begin
if old.A > 2 * old.B then
signal sqlstate '45000'
set message_text = 'Error: A > 2*B';
end if;
end;
$$

delete from R
where B = 2;

create table R1
(	A int,
	B int);
    
create table R2
(	B int,
	C int);

delimiter $$
create trigger insert_R1 before insert on R1
for each row
begin
if Exists (Select *
			From R2
			Where new.B = B 
            and new.A <= C ) then
signal sqlstate '45000'
set message_text = 'Insert R1 Error: A <= C';
end if;
end;
$$

delimiter $$
create trigger insert_R1 before update on R1
for each row
begin
if Exists (Select *
			From R2
			Where new.B = B 
            and new.A <= C ) then
signal sqlstate '45000'
set message_text = 'Insert R1 Error: A <= C';
end if;
end;
$$

delimiter $$
create trigger insert_R2 before insert on R2
for each row
begin
if Exists (Select *
			From R1
			Where new.B = B 
            and new.C >= A ) then
signal sqlstate '45000'
set message_text = 'Insert R1 Error: A <= C';
end if;
end;
$$

delimiter $$
create trigger update_R2 before update on R2
for each row
begin
if Exists (Select *
			From R1
			Where new.B = B 
            and new.C >= A ) then
signal sqlstate '45000'
set message_text = 'Insert R1 Error: A <= C';
end if;
end;
$$
