-- phpMyAdmin SQL Dump
-- version 4.9.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- 생성 시간: 19-11-24 03:31
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
-- 테이블 구조 `orderlist`
--

CREATE TABLE `orderlist` (
  `num` int(10) NOT NULL,
  `name` varchar(20) NOT NULL,
  `filename` varchar(50) NOT NULL,
  `price` int(10) NOT NULL,
  `amount` int(3) NOT NULL,
  `totalprice` int(10) NOT NULL,
  `userid` varchar(10) NOT NULL,
  `gubon` varchar(10) NOT NULL,
  `state` varchar(10) NOT NULL DEFAULT '대기'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `orderlist`
--

INSERT INTO `orderlist` (`num`, `name`, `filename`, `price`, `amount`, `totalprice`, `userid`, `gubon`, `state`) VALUES
(63, '포스트 잇', 'data/main111_17_08_20.jpg', 2000, 1, 2000, 'php123', '주문', '대기'),
(66, '다용도 책상', 'data/main211_17_08_32.jpg', 12000, 1, 12000, 'php123', '장바구니', '대기'),
(68, '포스트 잇', 'data/main111_17_08_20.jpg', 2000, 1, 2000, 'php123', '장바구니', '대기'),
(123, '다용도 책상', 'data/main211_17_08_32.jpg', 12000, 1, 12000, 'levell', '주문', '대기'),
(144, '다용도 책상', 'data/main211_17_08_32.jpg', 12000, 2, 24000, 'whddnr0317', '주문', '주문확정'),
(145, '아아아', 'data/intro211_17_10_04.jpg', 1000, 1, 1000, 'whddnr0317', '주문', '대기'),
(149, '간단 수납장', 'data/product2_311_21_07_32.jpg', 40000, 1, 40000, 'levell', '주문', '대기'),
(150, '포스트 잇', 'data/main111_17_08_20.jpg', 3000, 1, 3000, 'levell', '주문', '주문확정'),
(151, '포스트 잇', 'data/main111_17_08_20.jpg', 3000, 1, 3000, 'levell', '주문', '주문확정'),
(153, '포스트 잇', 'data/main111_17_08_20.jpg', 3000, 3, 9000, 'levell', '주문', '대기'),
(154, '다용도 책상', 'data/main211_17_08_32.jpg', 12000, 1, 12000, 'levell', '주문', '주문확정'),
(157, '제품3', 'data/intro111_18_01_13.jpg', 100000, 1, 100000, 'goe0317', '장바구니', '대기'),
(158, '아아아', 'data/intro211_17_10_04.jpg', 1000, 1, 1000, 'goe0317', '주문', '대기'),
(159, '아아아', 'data/intro211_17_10_04.jpg', 1000, 1, 1000, 'levell', '주문', '대기'),
(160, '아아아', 'data/intro211_17_10_04.jpg', 1000, 1, 1000, 'levell', '주문', '대기');

--
-- 덤프된 테이블의 인덱스
--

--
-- 테이블의 인덱스 `orderlist`
--
ALTER TABLE `orderlist`
  ADD PRIMARY KEY (`num`);

--
-- 덤프된 테이블의 AUTO_INCREMENT
--

--
-- 테이블의 AUTO_INCREMENT `orderlist`
--
ALTER TABLE `orderlist`
  MODIFY `num` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=161;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
