-- ﷽
-- Contest: Binary Search
--
-- Judge: Virtual Judge
-- URL: https://vjudge.net/contest/667521#problem/B
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
-- Comments :  wtf is this language i got headache

import Control.Monad
import Data.Array
import Data.List
import Debug.Trace
import Numeric

solve :: Int -> Int -> [Int] -> Integer
solve n d xs = solve' (1, 1)
  where
    a = listArray (1, n) xs
    solve' (i, j)
      | j == n = f (j - i)
      | otherwise = f (j - i) + solve'' (i, j + 1)
    solve'' (i, j)
      | a ! j - a ! i > d = solve'' (i + 1, j)
      | otherwise = solve' (i, j)
    f :: Int -> Integer
    f n = (n' * (n' - 1)) `div` 2
      where
        n' = fromIntegral n

solveTestCase = do

  l1 <- fmap (map read . words) getLine :: IO [Int]
  let n = l1 !! 0
      d = l1 !! 1
  cords <- fmap (map read . words) getLine :: IO [Int]

  -- mapM_ print a
  print $ solve n d cords

main = do
  -- numTests <- readLn :: IO Int
  let numTests = 1
  replicateM numTests $ do
    solveTestCase
