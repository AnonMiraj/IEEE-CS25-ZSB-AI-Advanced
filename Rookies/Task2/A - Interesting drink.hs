-- ﷽
-- Contest: Binary Search
--
-- Judge: Virtual Judge
-- URL: https://vjudge.net/contest/667521#problem/A
-- Memory Limit: 256
-- Time Limit: 2000
-- Start: Thu 05 Dec 2024 12:53:46 PM EET
-- Reading Time :
-- Thinking Time :
-- Coding Time :
-- Debug Time :
-- Submit Count :
-- Problem Level :
-- Category :
-- Comments :
--
import Control.Monad
import Data.Array
import Data.List
import Debug.Trace
import Numeric

upperBound :: Array Int Int -> Int -> Int
upperBound xs target = go 0 (length xs)
  where
    go low high
      | low >= high = low
      | otherwise =
          let mid = (low + high) `div` 2
           in if xs ! mid <= target
                then go (mid + 1) high
                else go low mid

solveTestCase = do
  n <- readLn :: IO Int
  prices <- fmap (map read . words) getLine :: IO [Int]
  q <- readLn :: IO Int
  queries <- replicateM q $ readLn :: IO [Int]

  let a = listArray (0, n - 1) $ sort prices :: Array Int Int
  -- let arr = listArray (0, n - 1) sprices

  let results = map (\q -> upperBound a q) queries
  -- mapM_ print a
  mapM_ print results

main = do
  -- numTests <- readLn :: IO Int
  let numTests = 1
  replicateM numTests $ do
    solveTestCase
