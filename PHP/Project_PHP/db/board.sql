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
-- 테이블 구조 `board`
--

CREATE TABLE `board` (
  `num` int(11) NOT NULL,
  `id` char(15) NOT NULL,
  `name` char(10) NOT NULL,
  `subject` char(200) NOT NULL,
  `content` text NOT NULL,
  `regist_day` char(30) NOT NULL,
  `hit` int(11) NOT NULL,
  `file_name` char(40) DEFAULT NULL,
  `file_type` char(40) DEFAULT NULL,
  `file_copied` char(40) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `board`
--

INSERT INTO `board` (`num`, `id`, `name`, `subject`, `content`, `regist_day`, `hit`, `file_name`, `file_type`, `file_copied`) VALUES
(61, 'levell', '김종욱', '123', '123', '2019-11-18 (03:38:43)', 7, '', '', ''),
(72, 'php123', 'PHP', '안녕하세요', '안녕하세요', '2019-11-18 (04:12:24)', 12, '', '', ''),
(73, 'whddnr0317', '김종욱', '112333', '123123213', '2019-11-21 (06:34:33)', 14, 'intro1.jpg', 'image/jpeg', 'intro12019_11_21_06_34_33.jpg'),
(74, 'whddnr0317', '김종욱', 'ASD', 'ASD', '2019-11-21 (06:41:26)', 9, '', '', ''),
(75, 'wlsdud123', '박진영', '역시 아이유', '아이유 신곡좋습니다 ! ', '2019-11-23 (08:11:14)', 11, 'iu.jpg', 'image/jpeg', 'iu2019_11_23_08_11_14.jpg'),
(76, 'php123', 'PHP', '가구너무 좋네요', '너무 싸고 좋네요', '2019-11-23 (08:26:30)', 3, 'product2_3.jpg', 'image/jpeg', 'product2_32019_11_23_08_26_30.jpg'),
(77, 'php123', 'PHP', '게시판 예제', '게시판 예제', '2019-11-23 (08:28:36)', 0, '', '', ''),
(78, 'php123', 'PHP', '게시판 예제12', '112', '2019-11-23 (08:28:41)', 1, '', '', ''),
(79, 'php123', 'PHP', '게시판 예제', '213123', '2019-11-23 (08:28:45)', 2, '', '', ''),
(80, 'php123', 'PHP', '123', '1232', '2019-11-23 (08:28:49)', 5, '', '', ''),
(81, 'levell', '김종욱', '안녕하세요', '테스트\r\n', '2019-11-24 (03:27:03)', 1, '600.jpg', 'image/jpeg', '6002019_11_24_03_27_03.jpg');

--
-- 덤프된 테이블의 인덱스
--

--
-- 테이블의 인덱스 `board`
--
ALTER TABLE `board`
  ADD PRIMARY KEY (`num`);

--
-- 덤프된 테이블의 AUTO_INCREMENT
--

--
-- 테이블의 AUTO_INCREMENT `board`
--
ALTER TABLE `board`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=82;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
