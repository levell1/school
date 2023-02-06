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
-- 테이블 구조 `members`
--

CREATE TABLE `members` (
  `num` int(11) NOT NULL,
  `id` char(15) NOT NULL,
  `pass` char(15) NOT NULL,
  `name` char(10) NOT NULL,
  `email` char(80) DEFAULT NULL,
  `regist_day` char(20) DEFAULT NULL,
  `level` int(11) DEFAULT NULL,
  `point` int(11) DEFAULT NULL,
  `addr` char(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `members`
--

INSERT INTO `members` (`num`, `id`, `pass`, `name`, `email`, `regist_day`, `level`, `point`, `addr`) VALUES
(22, 'levell', 'last0317', '김종욱', 'whddnr0317@naver.com', '2019-10-07 (05:18)', 1, 45540, '12123'),
(31, 'Test11', '123123', '테스트', 'whddnr0317@naver.com', '2019-11-18 (01:05)', 9, 2000, '123'),
(32, 'php123', 'php123', 'PHP', '123@naver.com', '2019-11-18 (04:10)', 9, 150, '주소'),
(33, 'PHP111', '1', 'PHP', 'PHP@naver.com', '2019-11-21 (08:12)', 1, 98000, 'PHP'),
(36, 'wlsdud123', 'wlsdud12', '박진영', 'YNC2@naver.com', '2019-11-23 (08:09)', 9, 10, '영남이공대'),
(37, 'goe0317', '123123', '김민지', 'goe0317@naver.com', '2019-11-24 (03:13)', 9, 9000, '아러아');

--
-- 덤프된 테이블의 인덱스
--

--
-- 테이블의 인덱스 `members`
--
ALTER TABLE `members`
  ADD PRIMARY KEY (`num`);

--
-- 덤프된 테이블의 AUTO_INCREMENT
--

--
-- 테이블의 AUTO_INCREMENT `members`
--
ALTER TABLE `members`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=38;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
