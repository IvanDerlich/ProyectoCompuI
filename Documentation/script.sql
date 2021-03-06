-- MySQL Script generated by MySQL Workbench
-- Thu 05 Jan 2017 10:25:55 PM ART
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
-- -----------------------------------------------------
-- Schema AsistenteFinanciero
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema AsistenteFinanciero
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `AsistenteFinanciero` DEFAULT CHARACTER SET utf8 ;
USE `AsistenteFinanciero` ;

-- -----------------------------------------------------
-- Table `AsistenteFinanciero`.`CategoriasGasto`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `AsistenteFinanciero`.`CategoriasGasto` (
  `idCategoriaGasto` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NOT NULL,
  `descripcion` VARCHAR(200) NULL DEFAULT NULL,
  PRIMARY KEY (`idCategoriaGasto`))
ENGINE = InnoDB
AUTO_INCREMENT = 2
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `AsistenteFinanciero`.`CategoriasIngreso`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `AsistenteFinanciero`.`CategoriasIngreso` (
  `idCategoriaIngreso` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NOT NULL,
  `descripcion` VARCHAR(200) NULL DEFAULT NULL,
  PRIMARY KEY (`idCategoriaIngreso`))
ENGINE = InnoDB
AUTO_INCREMENT = 2
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `AsistenteFinanciero`.`Gastos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `AsistenteFinanciero`.`Gastos` (
  `idGasto` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `categoria` INT(10) UNSIGNED NOT NULL,
  `concepto` VARCHAR(45) NOT NULL,
  `fecha` DATE NOT NULL,
  `monto` INT(10) UNSIGNED NOT NULL,
  `comentarios` VARCHAR(200) NULL DEFAULT NULL,
  PRIMARY KEY (`idGasto`),
  INDEX `fk_Gastos_1_idx` (`categoria` ASC),
  CONSTRAINT `fk_Gastos_1_Categoria`
    FOREIGN KEY (`categoria`)
    REFERENCES `AsistenteFinanciero`.`CategoriasGasto` (`idCategoriaGasto`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 2
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `AsistenteFinanciero`.`Ingresos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `AsistenteFinanciero`.`Ingresos` (
  `idIngreso` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `categoria` INT(10) UNSIGNED NOT NULL,
  `concepto` VARCHAR(45) NOT NULL,
  `fecha` DATE NOT NULL,
  `monto` INT(10) UNSIGNED NOT NULL,
  `comentarios` VARCHAR(200) NULL DEFAULT NULL,
  PRIMARY KEY (`idIngreso`),
  INDEX `fk_Ingresos_1_Categoria_idx` (`categoria` ASC),
  CONSTRAINT `fk_Ingresos_1_Categoria`
    FOREIGN KEY (`categoria`)
    REFERENCES `AsistenteFinanciero`.`CategoriasIngreso` (`idCategoriaIngreso`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 2
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `AsistenteFinanciero`.`Listas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `AsistenteFinanciero`.`Listas` (
  `idLista` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NOT NULL,
  `descripcion` VARCHAR(200) NULL DEFAULT NULL,
  PRIMARY KEY (`idLista`))
ENGINE = InnoDB
AUTO_INCREMENT = 2
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `AsistenteFinanciero`.`Items`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `AsistenteFinanciero`.`Items` (
  `idItem` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `lista` INT(10) UNSIGNED NOT NULL,
  `nombre` VARCHAR(45) NOT NULL,
  `descripcion` VARCHAR(200) NULL DEFAULT NULL,
  PRIMARY KEY (`idItem`),
  INDEX `fk_Items_1_Lista_idx` (`lista` ASC),
  CONSTRAINT `fk_Items_1_Lista`
    FOREIGN KEY (`lista`)
    REFERENCES `AsistenteFinanciero`.`Listas` (`idLista`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 2
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `AsistenteFinanciero`.`Recordatorios`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `AsistenteFinanciero`.`Recordatorios` (
  `idRecordatorio` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `fecha` DATE NOT NULL,
  `nombre` VARCHAR(45) NOT NULL,
  `descripcion` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`idRecordatorio`))
ENGINE = InnoDB
AUTO_INCREMENT = 2
DEFAULT CHARACTER SET = utf8;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
