create database QLDDH;
use QLDDH;

create table LOAIHG
(	MALH char(3) primary key,
	TENLH varchar(30));

insert into LOAIHG
values ('L01','Nong San'),
	('L02','Thuy San'),
	('L03','Nuoc Ngot'),
	('L04','Gia Vi'),
	('L05','Trai Cay');

create table HANG 
(	MAHG char(3) primary key,
	TENHG varchar(30),
	DG int,
	MALH char(3));

insert into HANG
values ('H01','Rau cai',5000,'L01'),
		('H02','Rau xa lach',4500,'L01'),
        ('H03','Rau muong',3500,'L01'),
        ('H04','Rau mong toi',5000,'L01'),
        ('H05','Rau ngot',6000,'L01'),
        ('H06','Rau ma',6500,'L01'),
        ('H07','Ca',15000,'L02'),
        ('H08','Tom',30000,'L02'),
        ('H09','Cua',35000,'L02'),
        ('H10','Muc',40000,'L02'),
        ('H11','Oc',50000,'L02'),
        ('H12','Bach tuoc',37000,'L02'),
        ('H13','Sting',10000,'L03'),
        ('H14','Coca',10000,'L03'),
        ('H15','Pepsi',10000,'L03'),
        ('H16','Redbull',12000,'L03'),
        ('H17','7up',12000,'L03'),
        ('H18','Fanta',8000,'L03'),
        ('H19','Hat nem',10000,'L04'),
        ('H20','Bot ngot',15000,'L04'),
        ('H21','Bot canh',10000,'L04'),
        ('H22','Muoi',12000,'L04'),
        ('H23','Nuoc mam',30000,'L04'),
        ('H24','Sot gia vi',15000,'L04'),
        ('H25','Dua hau',15600,'L05'),
        ('H26','Tao',13000,'L05'),
		  ('H27','Xoai',25000,'L05'),
        ('H28','Buoi',13000,'L05'),
        ('H29','Cam',15000,'L05'),
        ('H30','Vai',21000,'L05');

create table KHACH
( MAKH char(3) primary key,
	TENKH varchar(30),
	DCKH varchar(30),
	DTKH int);

insert into KHACH
values
	('K01', 'Nam', 'Go Vap', 0948238952),	('K02', 'Tung', 'Binh Thanh', 0895828394),
	('K03', 'Son', 'Go Dau', 0795294895),
	('K04', 'Nhat', 'Quan 5', 0958919295),
	('K05', 'Phat', 'Quan 1', 0998981234),
	('K06', 'Nghia', 'Quan 10', 0895581238),
	('K07', 'Hung', 'Quan 2', 0959185782);

create table DDH 
(	MADDH char(3) primary key,
	NGDH date,
	NGHL date,
	MAKH char(3));

drop table DDH;

insert into DDH
values 
	('D01','2023-01-01','2023-01-05','K01'),
	('D02','2023-03-01','2023-03-06','K02'),
	('D03','2023-12-03','2023-12-06','K02'),
	('D04','2023-12-03','2023-12-08','K03'),
	('D05','2023-12-03','2023-12-04','K04'),
	('D06','2023-12-05','2023-12-08','K05'),
	('D07','2023-12-06','2023-12-08','K05'),
	('D08','2023-12-08','2023-12-09','K01'),
	('D09','2023-12-08','2023-12-10','K03'),
	('D10','2023-12-09','2023-12-10','K05');

create table CTDDH
(	MADDH char(3),
	MAHG char(3),
	SLD int);
drop table CTDDH;

insert into CTDDH
values 
	('D01','H01',3),
	('D01','H05',7),
	('D01','H07',8),
	('D01','H02',5),
	('D02','H04',5),
	('D02','H05',3),
	('D03','H11',3),
	('D03','H14',5),
	('D04','H20',7),
	('D05','H29',3),
	('D05','H22',1),
	('D05','H21',3),
	('D05','H11',0),
	('D05','H10',3),
	('D06','H11',9),
	('D06','H12',9),
	('D06','H13',3),
	('D07','H07',7),
	('D07','H09',8),
	('D08','H01',8),
	('D09','H09',3),
	('D09','H10',6),
	('D10','H22',6),
	('D10','H10',3),
	('D10','H30',2);

create table DOTGH 
(	MADGH char(3) primary key,
	NGGH date,
	MADDH char(3));

drop table DOTGH;

insert into DOTGH
values
	('G01','2023-12-05','D01'),
	('G02','2023-12-05','D01'),
	('G03','2023-12-05','D01'),
	('G04','2023-12-06','D02'),
	('G05','2023-12-06','D03'),
	('G06','2023-12-06','D03'),
	('G07','2023-12-08','D04'),
	('G08','2023-12-04','D05'),
	('G09','2023-12-04','D05'),
	('G10','2023-12-04','D05');

create table CTDGH
(	MADGH char(3),
	MAHG char(3),
	SLG int);

insert into CTDGH
values
	('G01','H01',3),
	('G01','H02',5),
	('G02','H05',7),
	('G03','H07',8),
	('G04','H04',5),
	('G04','H05',5),
	('G05','H11',3),
	('G06','H14',5),
	('G07','H20',7),
	('G08','H29',3),
	('G08','H22',1),
	('G08','H21',3),
	('G09','H11',0),
	('G10','H10',3);

-- 5.1. Các khách hàng (mã số) đặt hàng từ ngày d1 đến ngày d2.

select distinct MAKH
from DDH 
where NGDH between '2023-12-01' and '2023-12-05';

-- 5.2. Các khách hàng (mã số, tên và địa chỉ) đặt hàng trong năm 2023.

select distinct A.MAKH,B.TENKH,B.DCKH
from DDH A,KHACH B
where year(NGDH) = 2023
	and A.MAKH = B.MAKH;

-- 5.3. các mặt hàng (mã số) đặt trong đơn đặt hàng mã số ”D01”.

select MAHG
from CTDDH
where MADDH = 'D01';

-- 5.4. các mặt hàng (*) đặt trong đơn đặt hàng mã số ”D01”.

select B.*
from CTDDH A, HANG B
where MADDH = 'D01'
	and A.MAHG = B.MAHG;

-- 5.5. Tổng số lượng đặt của từng đơn đặt hàng.

select MADDH,SUM(SLD) as 'Tong SL'
from CTDDH 
group by MADDH;

-- 5.6. Tổng số lượng đặt của từng đơn đặt hàng trong quý 1 năm 2023.
select B.MADDH, SUM(SLD)
from CTDDH A, DDH B 
where year(B.NGDH) = 2023
	and quarter(B.NGDH) = 1 
	and A.MADDH = B.MADDH
group by B.MADDH;

-- 5.7. Tính trị giá của từng đơn đặt hàng
select A.MADDH,sum(SLD*DG) as 'Tri Gia'
from CTDDH A, HANG B
where A.MAHG = B.MAHG
group by A.MADDH;

-- 5.8. Đơn đặt hàng nào có trị giá lớn nhất.
select A.MADDH,sum(SLD*DG) as 'Tri Gia'
from CTDDH A, HANG B
where A.MAHG = B.MAHG
group by A.MADDH
having sum(SLD*DG) >= ALL 
	(select sum(SLD*DG)
	from CTDDH A, HANG B 
	where A.MAHG = B.MAHG
	group by A.MADDH);

-- 5.9. Tổng trị giá đặt hàng của từng khách hàng (mã số).
select B.MAKH, sum(SLD*DG) as 'Tri Gia'
from CTDDH A, DDH B, HANG C
where A.MAHG = C.MAHG
	and A.MADDH = B.MADDH
group by B.MAKH;

-- 5.10. Tổng trị giá đặt hàng của từng khách hàng (mã số và tên).
select D.MAKH,D.TENKH, sum(SLD*DG) as 'Tri Gia'
from CTDDH A, DDH B, HANG C, KHACH D
where A.MAHG = C.MAHG
	and A.MADDH = B.MADDH
	and B.MAKH = D.MAKH
group by D.MAKH, D.TENKH;

-- 5.11. Tổng trị giá đặt hàng của từng quý trong năm 2023.
select quarter(B.NGDH) as 'Quy', SUM(SLD*DG) as 'Tri Gia'
from CTDDH A, DDH B, HANG C
where year(B.NGDH) = 2023 
	and A.MADDH = B.MADDH
	and A.MAHG = C.MAHG
group by quarter(B.NGDH);

-- 5.12. Trong năm 2023, tháng nào có tổng trị giá giao hàng lớn nhất.
select month(B.NGDH) as  'Tháng', SUM(SLD*DG) as 'Trị giá'
from CTDDH A, DDH B, HANG C
where year(B.NGDH) = 2023 
	and A.MADDH = B.MADDH
	and A.MAHG = C.MAHG
group by month(B.NGDH)
having SUM(SLD*DG) >= ALL
	(select SUM(SLD*DG)
	from CTDDH A, DDH B, HANG C
	where year(B.NGDH) = 2023 
		and A.MADDH = B.MADDH
		and A.MAHG = C.MAHG
	group by month(B.NGDH));

-- 5.13. Đơn đặt hàng nào được đặt tất cả các mặt hàng của loại hàng mã số ”L01”.

-- 5.14. Đơn đặt hàng nào được giao nhiều đợt nhất.
select MADDH, count(MADGH) as 'Số lần giao'
from DOTGH
group by MADDH
having count(MADDH) >= ALL
	(select count(MADGH)
	from DOTGH
	group by MADDH);
