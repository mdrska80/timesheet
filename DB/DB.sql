-- Valentina Studio --
-- MySQL dump --
-- ---------------------------------------------------------


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
-- ---------------------------------------------------------


-- CREATE DATABASE "timesheetdb" ---------------------------
CREATE DATABASE IF NOT EXISTS `timesheetdb` CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `timesheetdb`;
-- ---------------------------------------------------------


-- CREATE TABLE "CONFIG" -----------------------------------
CREATE TABLE `CONFIG` ( 
	`CONFIGID` Int( 11 ) AUTO_INCREMENT NOT NULL, 
	`CODE` VarChar( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL, 
	`VALUE` VarChar( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
	 PRIMARY KEY ( `CONFIGID` )
 )
CHARACTER SET = utf8
COLLATE = utf8_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 1;
-- ---------------------------------------------------------


-- CREATE TABLE "ENTRY" ------------------------------------
CREATE TABLE `ENTRY` ( 
	`ENTRYID` Int( 255 ) AUTO_INCREMENT NOT NULL, 
	`DATE` Date NOT NULL, 
	`FROM` Time NOT NULL, 
	`TO` Time NOT NULL, 
	`TITLE` VarChar( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL, 
	`DESCRIPTION` VarChar( 2048 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL, 
	`PARENT` Int( 255 ) NULL, 
	`PROJECTID` Int( 255 ) NULL,
	 PRIMARY KEY ( `ENTRYID` )
 )
CHARACTER SET = utf8
COLLATE = utf8_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 8;
-- ---------------------------------------------------------


-- CREATE TABLE "PROJECT" ----------------------------------
CREATE TABLE `PROJECT` ( 
	`PROJECTID` Int( 255 ) AUTO_INCREMENT NOT NULL, 
	`NAME` VarChar( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL, 
	`DESCRIPTION` VarChar( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL, 
	`PARENT` Int( 255 ) NULL, 
	`COMPANYID` Int( 255 ) NULL,
	 PRIMARY KEY ( `PROJECTID` )
 )
CHARACTER SET = utf8
COLLATE = utf8_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 3;
-- ---------------------------------------------------------


-- CREATE TABLE "COMPANY" ----------------------------------
CREATE TABLE `COMPANY` ( 
	`COMPANYID` Int( 255 ) AUTO_INCREMENT NOT NULL, 
	`NAME` VarChar( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL, 
	`DESCRIPTION` VarChar( 2048 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL, 
	`URL` VarChar( 1024 ) CHARACTER SET utf8 COLLATE utf8_general_ci NULL, 
	`FROM` Date NULL, 
	`TO` Date NULL,
	 PRIMARY KEY ( `COMPANYID` )
 )
CHARACTER SET = utf8
COLLATE = utf8_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 5;
-- ---------------------------------------------------------


-- Dump data of "CONFIG" -----------------------------------
-- ---------------------------------------------------------


-- Dump data of "ENTRY" ------------------------------------
INSERT INTO `ENTRY`(`ENTRYID`,`DATE`,`FROM`,`TO`,`TITLE`,`DESCRIPTION`,`PARENT`,`PROJECTID`) VALUES ( '1', '2013-12-16', '10:00:00', '12:00:00', 'Titulek', 'Sirsi popis', NULL, '2' );
INSERT INTO `ENTRY`(`ENTRYID`,`DATE`,`FROM`,`TO`,`TITLE`,`DESCRIPTION`,`PARENT`,`PROJECTID`) VALUES ( '7', '2013-12-15', '12:00:00', '16:00:00', 'Titulek 2', 'Dalsi popis', NULL, '2' );
-- ---------------------------------------------------------


-- Dump data of "PROJECT" ----------------------------------
INSERT INTO `PROJECT`(`PROJECTID`,`NAME`,`DESCRIPTION`,`PARENT`,`COMPANYID`) VALUES ( '2', 'Test project', 'Naprosto nullove polozky', NULL, '0' );
-- ---------------------------------------------------------


-- Dump data of "COMPANY" ----------------------------------
INSERT INTO `COMPANY`(`COMPANYID`,`NAME`,`DESCRIPTION`,`URL`,`FROM`,`TO`) VALUES ( '1', 'Unicorn', 'Unicorn', 'http://www.unicorn.eu', '0000-00-00', '0000-00-00' );
INSERT INTO `COMPANY`(`COMPANYID`,`NAME`,`DESCRIPTION`,`URL`,`FROM`,`TO`) VALUES ( '2', 'ka.soft', 'ka soft', 'http://www.ka.cz', '0000-00-00', '0000-00-00' );
INSERT INTO `COMPANY`(`COMPANYID`,`NAME`,`DESCRIPTION`,`URL`,`FROM`,`TO`) VALUES ( '3', 'AutoCont', 'AutoCont', 'http://www.autocont.cz', '0000-00-00', '0000-00-00' );
INSERT INTO `COMPANY`(`COMPANYID`,`NAME`,`DESCRIPTION`,`URL`,`FROM`,`TO`) VALUES ( '4', 'Bustec', 'Bustec', 'http://bustec-info.eu/cs', '0000-00-00', '0000-00-00' );
-- ---------------------------------------------------------


-- CREATE INDEX "CONFIGUnique" -----------------------------
CREATE UNIQUE INDEX `CONFIGUnique` USING BTREE ON `CONFIG`( `CONFIGID` );
-- ---------------------------------------------------------


-- CREATE INDEX "lnk_PROJECT_PROJECT" ----------------------
CREATE INDEX `lnk_PROJECT_PROJECT` USING BTREE ON `PROJECT`( `PARENT` );
-- ---------------------------------------------------------


-- CREATE LINK "lnk_ENTRY_PROJECT" -------------------------
ALTER TABLE `ENTRY` ADD CONSTRAINT `lnk_ENTRY_PROJECT` FOREIGN KEY ( `PROJECTID` ) REFERENCES `PROJECT`( `PROJECTID` ) ON DELETE Cascade ON UPDATE Cascade;
-- ---------------------------------------------------------


-- CREATE LINK "lnk_ENTRY_ENTRY" ---------------------------
ALTER TABLE `ENTRY` ADD CONSTRAINT `lnk_ENTRY_ENTRY` FOREIGN KEY ( `PARENT` ) REFERENCES `ENTRY`( `ENTRYID` ) ON DELETE Cascade ON UPDATE Cascade;
-- ---------------------------------------------------------


-- CREATE LINK "lnk_PROJECT_PROJECT" -----------------------
ALTER TABLE `PROJECT` ADD CONSTRAINT `lnk_PROJECT_PROJECT` FOREIGN KEY ( `PARENT` ) REFERENCES `PROJECT`( `PROJECTID` ) ON DELETE Cascade ON UPDATE Cascade;
-- ---------------------------------------------------------


-- CREATE VIEW "TodayEntriesView" --------------------------
CREATE OR REPLACE ALGORITHM = UNDEFINED DEFINER = `root`@`localhost` SQL SECURITY DEFINER VIEW `TodayEntriesView`
AS -- zaajimaji nas jen dnesni zaznamy
SELECT * FROM ENTRY WHERE DATE = curdate();
-- ---------------------------------------------------------


-- CREATE VIEW "ThisWeekEntriesView" -----------------------
CREATE OR REPLACE ALGORITHM = UNDEFINED DEFINER = `root`@`localhost` SQL SECURITY DEFINER VIEW `ThisWeekEntriesView`
AS -- week pro nas nezacina nedeli, ale pondelim. Proto to plus 1.
-- no a pricitat jeden den v pondeli je blbost, proto jeste jedno minus
SELECT 
*,
CURDATE() AS DEBUG_DNES,
DAYOFWEEK(CURDATE())-1 AS DEBUG_PORADI_DNE,
CURDATE() - INTERVAL DAYOFWEEK(CURDATE())-2 DAY AS DEBUG_START_TOHOTO_TYDNE,
CURDATE() + INTERVAL 7-DAYOFWEEK(CURDATE())+1 DAY AS DEBUG_KONEC_TOHOTO_TYDNE
 FROM ENTRY WHERE DATE 
	BETWEEN 
		CURDATE() - INTERVAL DAYOFWEEK(CURDATE())-2 DAY AND 
		CURDATE() + INTERVAL 7-DAYOFWEEK(CURDATE())+1 DAY;
 ORDER BY DATE, FROM DESC;
-- ---------------------------------------------------------


/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
-- ---------------------------------------------------------


