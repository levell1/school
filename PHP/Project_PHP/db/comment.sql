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
-- 테이블 구조 `comment`
--

CREATE TABLE `comment` (
  `num` int(11) NOT NULL,
  `sub` varchar(50) NOT NULL,
  `user` varchar(20) NOT NULL,
  `content` varchar(100) NOT NULL,
  `date` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- 테이블의 덤프 데이터 `comment`
--

INSERT INTO `comment` (`num`, `sub`, `user`, `content`, `date`) VALUES
(58, '안녕하세요2019-11-18 (04:12:24)', 'php123', '123123', '2019-11-18 (04:20:21)'),
(59, '안녕하세요2019-11-18 (04:12:24)', 'whddnr0317', 'ASD', '2019-11-21 (06:29:26)'),
(60, '1123332019-11-21 (06:34:33)', 'whddnr0317', '123123', '2019-11-21 (06:34:37)'),
(63, '1123332019-11-21 (06:34:33)', 'whddnr0317', 'ASD', '2019-11-21 (06:41:28)'),
(64, '역시 아이유2019-11-23 (08:11:14)', 'levell', '?????', '2019-11-23 (08:11:28)'),
(65, 'ASD2019-11-21 (06:41:26)', 'levell', '댓글 ', '2019-11-23 (08:11:40)'),
(66, '1232019-11-18 (03:38:43)', 'levell', '123', '2019-11-23 (08:11:51)'),
(67, '역시 아이유2019-11-23 (08:11:14)', 'wlsdud123', '누구세요 ?', '2019-11-23 (08:11:51)'),
(69, '가구너무 좋네요2019-11-23 (08:26:30)', 'php123', 'ㅇㅇㅇㅇ', '2019-11-23 (08:28:15)'),
(70, '게시판 예제2019-11-23 (08:28:45)', 'php123', '댓글', '2019-11-23 (08:29:39)'),
(71, '1232019-11-23 (08:28:49)', 'PHP111', '댓글', '2019-11-23 (10:33:22)'),
(72, '1123332019-11-21 (06:34:33)', 'levell', '안녕하세요', '2019-11-24 (03:26:33)');

--
-- 덤프된 테이블의 인덱스
--

--
-- 테이블의 인덱스 `comment`
--
ALTER TABLE `comment`
  ADD PRIMARY KEY (`num`);

--
-- 덤프된 테이블의 AUTO_INCREMENT
--

--
-- 테이블의 AUTO_INCREMENT `comment`
--
ALTER TABLE `comment`
  MODIFY `num` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=73;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
