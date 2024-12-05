-- ﷽
-- Contest: Binary Search
--
-- Judge: Virtual Judge
-- URL: https://vjudge.net/contest/667521#problem/D
-- Memory Limit: 256
-- Time Limit: 2000
-- Start: Thu 05 Dec 2024 12:53:47 PM EET
-- Reading Time :
-- Thinking Time :
-- Coding Time :
-- Debug Time :
-- Submit Count :
-- Problem Level :
-- Category :
-- Comments :

import Control.Monad
import Data.Array
import Data.List
import Debug.Trace
import Numeric

main :: IO ()
main = do
  [n, t] <- fmap (map read . words) getLine

  aList <- fmap (map read . words) getLine
  let a = listArray (0, n - 1) aList

  let ans = maxBooks a t
  print ans

maxBooks :: Array Int Int -> Int -> Int
maxBooks a t = go 0 0 0 0
  where
    n = length a
    go l r sm maxLen
      | r == n = maxLen
      | sm + a ! r <= t = go l (r + 1) (sm + a ! r) (max maxLen (r - l + 1))
      | l < r = go (l + 1) r (sm - a ! l) maxLen
      | otherwise = go (l + 1) (r + 1) 0 maxLen
