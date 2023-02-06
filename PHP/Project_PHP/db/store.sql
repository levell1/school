-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- 생성 시간: 19-11-24 03:30
-- 서버 버전: 10.4.6-MariaDB
-- PHP 버전: 7.3.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 데이터베이스: `sample`
--

-- --------------------------------------------------------

--
-- 테이블 구조 `store`
--

CREATE TABLE `store` (
  `num` int(3) NOT NULL,
  `kind` varchar(20) DEFAULT NULL,
  `name` varchar(20) NOT NULL,
  `price` int(7) NOT NULL,
  `filename` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `store`
--

INSERT INTO `store` (`num`, `kind`, `name`, `price`, `filename`) VALUES
(1, '문구', '포스트 잇', 4000, 'main111_17_08_20.jpg'),
(2, '문구', '다용도 책상', 12000, 'main211_17_08_32.jpg'),
(45, '퀼트제품', '아아아', 1000, 'intro211_17_10_04.jpg'),
(46, '기타', '제품3', 100000, 'intro111_18_01_13.jpg'),
(47, '문구', '딱풀', 500, 'product311_21_07_27.jpg'),
(48, '문구', '미니수첩', 1500, 'product411_21_07_27.jpg'),
(49, '문구', '라이언세트', 5000, 'product111_21_07_27.jpg'),
(50, '문구', '롱수첩', 2000, 'product211_21_07_28.jpg'),
(51, '기타', '파랑수납장', 70000, 'product2_111_21_07_31.jpg'),
(52, '기타', '간단 수납장', 40000, 'product2_311_21_07_32.jpg'),
(53, '기타', '목재 수납장', 40000, 'product2_211_21_07_33.jpg'),
(54, '퀼트제품', '테스트', 50000, '60011_24_03_25.jpg');

--
-- 덤프된 테이블의 인덱스
--

--
-- 테이블의 인덱스 `store`
--
ALTER TABLE `store`
  ADD PRIMARY KEY (`num`);

--
-- 덤프된 테이블의 AUTO_INCREMENT
--

--
-- 테이블의 AUTO_INCREMENT `store`
--
ALTER TABLE `store`
  MODIFY `num` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=55;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
