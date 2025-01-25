import Control.Applicative
import Control.Monad
import Data.Array
import qualified Data.ByteString.Char8 as B
import Data.Foldable
import qualified Data.Set as S

readInt = maybe undefined fst . B.readInt

readInts = map readInt . B.words

main = do
  n <- readInt <$> B.getLine
  ps <- listArray (1, n) . readInts <$> B.getLine
  print . S.size . foldl' (\s (i, v) -> if ps ! v == i then S.insert (min v i) s else s) S.empty . assocs $ ps

